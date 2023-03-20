import model.Data;
import util.FileManager;
import util.Timer;

public class Local {

    private static final String THREAD_1_FILENAME = "local_1_result";
    private static final String THREAD_2_FILENAME = "local_2_result";

    public static void run(Data data) {
        System.out.println();
        System.out.println("Local start");
        Variant variant = new Variant(data);
        Thread t1 = new Thread(() -> {
            System.out.println("Thread 1 start");
            Timer timer = new Timer();
            timer.start();
            variant.calculateA();
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
            variant.calculateMA();
            double ms = timer.end();
            String result = String.format("Thread 2 finished in %s ms", ms);
            System.out.println("Thread 2 end");
            System.out.println(result);
            FileManager.write(THREAD_2_FILENAME, result);
        });
        t1.start();
        t2.start();
    }

}
