package model;

import util.Generator;
import util.Printable;

import java.util.Arrays;

public class Matrix implements Printable {

    private double[][] instance;
    private int size;

    public static Matrix generate(int size) {
        double[][] instance = Arrays.stream(new double[size][size])
                .map(vector -> Arrays.stream(vector)
                        .map(value -> Generator.randomDouble())
                        .toArray())
                .toArray(double[][]::new);
        return new Matrix(instance, size);
    }

    public static Matrix fromString(String input) {
        double[][] result = Arrays.stream(input.split(";"))
                .map(entry -> Arrays.stream(entry.split(","))
                        .map(Double::valueOf)
                        .mapToDouble(Double::doubleValue)
                        .toArray())
                .toArray(double[][]::new);
        return new Matrix(result, result.length);
    }

    public Matrix(double[][] instance, int size) {
        this.instance = instance;
        this.size = size;
    }

    public double[][] getInstance() {
        return instance;
    }

    public int getSize() {
        return size;
    }

    @Override
    public void print() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print(instance[i][j] + " ");
            }
            System.out.println();
        }
    }

    @Override
    public String toString() {
        return String.join(";", Arrays.stream(instance)
                .map(entry -> String.join(",", Arrays.stream(entry)
                        .mapToObj(String::valueOf)
                        .toArray(String[]::new)))
                .toArray(String[]::new));
    }
}
