package util;

import java.util.Random;

public class Generator {

    private static double MAX_DOUBLE = 100000;

    private static Random random = new Random();

    public static double randomDouble() {
        return random.nextDouble() * MAX_DOUBLE;
    }

}
