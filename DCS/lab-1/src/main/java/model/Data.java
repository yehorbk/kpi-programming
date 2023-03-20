package model;

import util.FileManager;
import util.Printable;

import java.util.Arrays;
import java.util.HashMap;

public class Data {

    private static final int DIMENSION = 1000;
    private static final String[] keys = {"a", "B", "D", "E", "MC", "MZ", "MM", "ML"};

    private Scalar a;
    private Vector B;
    private Vector D;
    private Vector E;
    private Matrix MC;
    private Matrix MZ;
    private Matrix MM;
    private Matrix ML;

    private HashMap<String, Object> nameDataMap;

    public static Data getData() {
        boolean isAllFilesExists = Arrays.stream(keys).allMatch(FileManager::checkIfExists);
        if (!isAllFilesExists) {
            Data data = new Data(
                    Scalar.generate(),
                    Vector.generate(DIMENSION),
                    Vector.generate(DIMENSION),
                    Vector.generate(DIMENSION),
                    Matrix.generate(DIMENSION),
                    Matrix.generate(DIMENSION),
                    Matrix.generate(DIMENSION),
                    Matrix.generate(DIMENSION)
            );
            data.nameDataMap.forEach(FileManager::write);
            return getData();
        } else {
            Scalar a = (Scalar) FileManager.read("a", Scalar::fromString);
            Vector B = (Vector) FileManager.read("B", Vector::fromString);
            Vector D = (Vector) FileManager.read("D", Vector::fromString);
            Vector E = (Vector) FileManager.read("E", Vector::fromString);
            Matrix MC = (Matrix) FileManager.read("MC", Matrix::fromString);
            Matrix MZ = (Matrix) FileManager.read("MZ", Matrix::fromString);
            Matrix MM = (Matrix) FileManager.read("MM", Matrix::fromString);
            Matrix ML = (Matrix) FileManager.read("ML", Matrix::fromString);
            return new Data(a, B, D, E, MC, MZ, MM, ML);
        }
    }

    public Data(Scalar a, Vector B, Vector D, Vector E, Matrix MC, Matrix MZ, Matrix MM, Matrix ML) {
        this.a = a;
        this.B = B;
        this.D = D;
        this.E = E;
        this.MC = MC;
        this.MZ = MZ;
        this.MM = MM;
        this.ML = ML;
        Object[] values = {a, B, D, E, MC, MZ, MM, ML};
        nameDataMap = new HashMap<>();
        for (int i = 0; i < keys.length; i++) {
            nameDataMap.put(keys[i], values[i]);
        }
    }

    public void print() {
        nameDataMap.forEach((key, value) -> {
            System.out.println(key + ":");
            ((Printable) value).print();
            System.out.println();
        });
    }

    public Scalar getA() {
        return a;
    }

    public Vector getB() {
        return B;
    }

    public Vector getD() {
        return D;
    }

    public Vector getE() {
        return E;
    }

    public Matrix getMC() {
        return MC;
    }

    public Matrix getMZ() {
        return MZ;
    }

    public Matrix getMM() {
        return MM;
    }

    public Matrix getML() {
        return ML;
    }
}
