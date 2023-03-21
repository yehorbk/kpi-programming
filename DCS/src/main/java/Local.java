import model.Data;
import model.Matrix;
import model.Vector;
import util.FileManager;
import util.Timer;

public class Local {

    private static final String A_FILENAME = "local_A";
    private static final String MA_FILENAME = "local_MA";

    private static final String A_TIME_FILENAME = "local_A_time";
    private static final String MA_TIME_FILENAME = "local_MA_time";

    public static void run(Data data) {
        System.out.println();
        System.out.println("Local start");
        System.out.println("Input:");
        data.print();
        Variant variant = new Variant(data);
        Thread t1 = new Thread(() -> {
            System.out.println("Thread 1 start");
            Timer timer = new Timer();
            timer.start();
            Vector A =  variant.calculateA();
            System.out.println("Result:");
            A.print();
            FileManager.write(A_FILENAME, A);
            double ms = timer.end();
            String result = String.format("Thread 1 finished in %s ms", ms);
            System.out.println("Thread 1 end");
            System.out.println(result);
            FileManager.write(A_TIME_FILENAME, result);
        });
        Thread t2 = new Thread(() -> {
            System.out.println("Thread 2 start");
            Timer timer = new Timer();
            timer.start();
            Matrix MA = variant.calculateMA();
            System.out.println("Result:");
            MA.print();
            FileManager.write(MA_FILENAME, MA);
            double ms = timer.end();
            String result = String.format("Thread 2 finished in %s ms", ms);
            System.out.println("Thread 2 end");
            System.out.println(result);
            FileManager.write(MA_TIME_FILENAME, result);
        });
        t1.start();
        t2.start();
    }

}
