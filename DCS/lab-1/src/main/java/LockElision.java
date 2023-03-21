import model.Data;
import model.Matrix;
import model.Vector;
import util.FileManager;
import util.Timer;

import java.util.concurrent.Callable;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class LockElision {

    private static final String A_FILENAME = "lock_elision_A";
    private static final String MA_FILENAME = "lock_elision_MA";

    private static final String TIME_FILENAME = "lock_elision_time";

    public static void run(Data data) {
        System.out.println();
        System.out.println("Lock Elision start");
        System.out.println("Input:");
        data.print();
        Variant variant = new Variant(data);
        Lock lock = new ReentrantLock();
        FirstCallable firstCallable = new FirstCallable(variant, lock);
        SecondCallable secondCallable = new SecondCallable(variant, lock);
        Timer timer = new Timer();
        timer.start();
        Vector A = firstCallable.call();
        System.out.println("A:");
        A.print();
        FileManager.write(A_FILENAME, A);
        Matrix MA = secondCallable.call();
        System.out.println("MA:");
        MA.print();
        FileManager.write(MA_FILENAME, MA);
        double ms = timer.end();
        String result = String.format("Lock Elision finished in %s ms", ms);
        System.out.println(result);
        FileManager.write(TIME_FILENAME, result);
    }

    private static class FirstCallable implements Callable<Vector> {
        private Variant variant;
        private Lock lock;

        public FirstCallable(Variant variant, Lock lock) {
            this.variant = variant;
            this.lock = lock;
        }

        @Override
        public Vector call() {
            System.out.println("Callable 1 start");
            lock.lock();
            try {
                return variant.calculateA();
            } finally {
                System.out.println("Callable 1 end");
                lock.unlock();
            }
        }
    }

    private static class SecondCallable implements Callable<Matrix> {
        private Variant variant;
        private Lock lock;

        public SecondCallable(Variant variant, Lock lock) {
            this.variant = variant;
            this.lock = lock;
        }

        @Override
        public Matrix call() {
            System.out.println("Callable 2 start");
            lock.lock();
            try {
                return variant.calculateMA();
            } finally {
                System.out.println("Callable 2 end");
                lock.unlock();
            }
        }
    }

}
