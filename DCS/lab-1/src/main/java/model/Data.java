package model;

import util.FileManager;
import util.Printable;

import java.util.Arrays;
import java.util.HashMap;

public class Data {

    private static final int DIMENSION = 1000;
    private static final String[] keys = {"B", "D", "MC", "MT", "ME", "MZ"};

    private Vector B;
    private Vector D;
    private Matrix MC;
    private Matrix MT;
    private Matrix ME;
    private Matrix MZ;

    private HashMap<String, Object> nameDataMap;

    public static Data getData() {
        boolean isAllFilesExists = Arrays.stream(keys).allMatch(FileManager::checkIfExists);
        if (!isAllFilesExists) {
            Data data = new Data(
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
            Vector B = (Vector) FileManager.read("B", Vector::fromString);
            Vector D = (Vector) FileManager.read("D", Vector::fromString);
            Matrix MC = (Matrix) FileManager.read("MC", Matrix::fromString);
            Matrix MT = (Matrix) FileManager.read("MT", Matrix::fromString);
            Matrix ME = (Matrix) FileManager.read("ME", Matrix::fromString);
            Matrix MZ = (Matrix) FileManager.read("MZ", Matrix::fromString);
            return new Data(B, D, MC, MT, ME, MZ);
        }
    }

    public Data(Vector B, Vector D, Matrix MC, Matrix MT, Matrix ME, Matrix MZ) {
        this.B = B;
        this.D = D;
        this.MC = MC;
        this.MT = MT;
        this.ME = ME;
        this.MZ = MZ;
        Object[] values = {B, D, MC, MT, ME, MZ};
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

    public Vector getB() {
        return B;
    }

    public Vector getD() {
        return D;
    }

    public Matrix getMC() {
        return MC;
    }

    public Matrix getMT() {
        return MT;
    }

    public Matrix getME() {
        return ME;
    }

    public Matrix getMZ() {
        return MZ;
    }
}
