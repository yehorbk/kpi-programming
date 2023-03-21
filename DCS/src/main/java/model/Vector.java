package model;

import util.Generator;
import util.Printable;

import java.util.Arrays;

public class Vector implements Printable {

    private double[] instance;
    private int size;

    public static Vector generate(int size) {
        double[] instance = Arrays.stream(new double[size])
                .map(value -> Generator.randomDouble())
                .toArray();
        return new Vector(instance, size);
    }

    public static Vector fromString(String input) {
        double[] result = Arrays.stream(input.split(","))
                .map(Double::valueOf)
                .mapToDouble(Double::doubleValue)
                .toArray();
        return new Vector(result, result.length);
    }

    public Vector(double[] instance, int size) {
        this.instance = instance;
        this.size = size;
    }

    public double[] getInstance() {
        return instance;
    }

    public int getSize() {
        return size;
    }

    @Override
    public void print() {
        for (int i = 0; i < size; i++) {
            System.out.print(instance[i] + " ");
        }
        System.out.println();
    }

    @Override
    public String toString() {
        return String.join(",", Arrays.stream(instance)
                .mapToObj(String::valueOf)
                .toArray(String[]::new));
    }
}
