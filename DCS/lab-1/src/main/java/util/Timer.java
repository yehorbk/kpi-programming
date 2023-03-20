package util;

public class Timer {

    private long startTime;

    public void start() {
        startTime = System.nanoTime();
    }

    public double end() {
        long endTime = System.nanoTime();
        return (endTime - startTime) / 100000.0;
    }

}
