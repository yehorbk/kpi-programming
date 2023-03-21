import model.Data;
import model.Matrix;
import model.Scalar;
import model.Vector;
import util.Calculator;

public class Variant {

    // VARIANT: 5
    // FORMULA:
    //  А=В*МС+D*MT;
    //  MА= min(D)*MC*ME+MZ*MT

    private Data data;

    public Variant(Data data) {
        this.data = data;
    }

    public Vector calculateA() {
        Vector BMC = Calculator.multiply(data.getMC(), data.getB()); // B*MC
        Vector DMT = Calculator.multiply(data.getMT(), data.getD()); // D*MT
        return Calculator.add(BMC, DMT); // A
    }

    public Matrix calculateMA() {
        Scalar minD = Calculator.min(data.getD()); // min(D)
        Matrix minDMCME = Calculator.multiply(Calculator.multiply(data.getMC(), data.getME()), minD); // min(D)*MC*ME
        Matrix MZMT = Calculator.multiply(data.getMZ(), data.getMT()); // MZ*MT
        return Calculator.add(minDMCME, MZMT); // MA
    }

}
