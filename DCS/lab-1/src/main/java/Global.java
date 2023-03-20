import model.Data;
import model.Matrix;
import model.Vector;
import util.FileManager;
import util.Timer;

public class Global {

    private static final String THREAD_1_FILENAME = "global_1_result";
    private static final String THREAD_2_FILENAME = "global_2_result";

    public static void run(Data data) {
        System.out.println();
        System.out.println("Global start");
        Variant variant = new Variant(data);
        SynchronizationManager synchronizationManager = new SynchronizationManager(variant);
        Thread t1 = new Thread(() -> {
            System.out.println("Thread 1 start");
            Timer timer = new Timer();
            timer.start();
            synchronizationManager.firstThreadRun();
            double ms = timer.end();
            String result = String.format("Thread 1 finished in %s ms", ms);
            System.out.println("Thread 1 end");
            System.out.println(result);
            FileManager.write(THREAD_1_FILENAME, result);
        });
        Thread t2 = new Thread(() -> {
            System.out.println("Thread 2 start");
            Timer timer = new Timer();
            timer.start();
            synchronizationManager.secondThreadRun();
            double ms = timer.end();
            String result = String.format("Thread 2 finished in %s ms", ms);
            System.out.println("Thread 2 end");
            System.out.println(result);
            FileManager.write(THREAD_2_FILENAME, result);
        });
        t1.start();
        t2.start();
    }

    private static class SynchronizationManager {
        private final Variant variant;
        private boolean threadSwitch = true;

        private Vector resultA;
        private Matrix resultMA;

        public SynchronizationManager(Variant variant) {
            this.variant = variant;
        }

        synchronized public void firstThreadRun() {
            while (!threadSwitch) {
                try {
                    wait();
                } catch (InterruptedException ie) {
                    ie.printStackTrace();
                }
            }
            resultA = variant.calculateA();
            threadSwitch = false;
            notify();
        }

        synchronized public void secondThreadRun() {
            while (threadSwitch) {
                try {
                    wait();
                } catch (InterruptedException ie) {
                    ie.printStackTrace();
                }
            }
            resultMA = variant.calculateMA();
            threadSwitch = true;
            notify();
        }
    }

}
