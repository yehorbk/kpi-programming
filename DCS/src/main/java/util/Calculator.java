package util;

import model.Matrix;
import model.Scalar;
import model.Vector;

public class Calculator {

    public static Matrix add(Matrix m1, Matrix m2) {
        int size = m1.getSize();
        double[][] result = new double[size][size];
        double[][] m1i = m1.getInstance();
        double[][] m2i = m2.getInstance();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i][j] = kahanSum(m1i[i][j], m2i[i][j]);
            }
        }
        return new Matrix(result, size);
    }

    public static Vector add(Vector v1, Vector v2) {
        int size = v1.getSize();
        double[] result = new double[size];
        double[] v1i = v1.getInstance();
        double[] v2i = v2.getInstance();
        for (int i = 0; i < size; i++) {
            result[i] = kahanSum(v1i[i], v2i[i]);
        }
        return new Vector(result, size);
    }

    public static Matrix multiply(Matrix m1, Matrix m2) {
        int size = m1.getSize();
        double[][] result = new double[size][size];
        double[][] m1i = m1.getInstance();
        double[][] m2i = m2.getInstance();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i][j] = 0;
                for (int k = 0; k < size; k++) {
                    result[i][j] = m1i[i][k] * m2i[k][j];
                }
            }
        }
        return new Matrix(result, size);
    }

    public static Vector multiply(Matrix m, Vector v) {
        int size = m.getSize();
        double[] result = new double[size];
        double[][] mi = m.getInstance();
        double[] vi = v.getInstance();
        for (int i = 0; i < size; i++) {
            result[i] = 0;
            for (int j = 0; j < size; j++) {
                result[i] = kahanSum(result[i], mi[i][j] * vi[j]);
            }
        }
        return new Vector(result, size);
    }

    public static Matrix multiply(Matrix m, Scalar s) {
        int size = m.getSize();
        double[][] result = new double[size][size];
        double[][] mi = m.getInstance();
        double si = s.getInstance();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i][j] = mi[i][j] * si;
            }
        }
        return new Matrix(result, size);
    }

    public static Scalar min(Vector vector) {
        double min = Double.MAX_VALUE;
        int size = vector.getSize();
        double[] vi = vector.getInstance();
        for (int i = 0; i < size; i++) {
            if (vi[i] < min) {
                min = vi[i];
            }
        }
        return new Scalar(min);
    }

    public static double kahanSum(double... items) {
        double sum = 0.0;
        double error = 0.0;
        for (double item : items) {
            double y = item - error;
            double z = sum + y;
            error = (z - sum) - y;
            sum = z;
        }
        return sum;
    }

}
