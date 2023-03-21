package model;

import util.Generator;
import util.Printable;

public class Scalar implements Printable {

    private double instance;

    public static Scalar generate() {
        return new Scalar(Generator.randomDouble());
    }

    public static Scalar fromString(String input) {
        return new Scalar(Double.valueOf(input));
    }

    public Scalar(double instance) {
        this.instance = instance;
    }

    public double getInstance() {
        return instance;
    }

    @Override
    public void print() {
        System.out.println(instance);
    }

    @Override
    public String toString() {
        return String.valueOf(instance);
    }
}
