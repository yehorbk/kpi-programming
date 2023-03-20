import model.Data;
import model.Matrix;
import model.Scalar;
import model.Vector;
import util.Calculator;

public class Variant {

    // VARIANT: 4
    // FORMULA:
    //  А=В*МС+D*MZ+E*MM;
    //  MА=max(D+B)*MZ*MM-ML*MC*a

    private Data data;

    public Variant(Data data) {
        this.data = data;
    }

    public Vector calculateA() {
        Vector BMC = Calculator.multiply(data.getMC(), data.getB()); // B*MC
        Vector DMZ = Calculator.multiply(data.getMZ(), data.getD()); // D*MZ
        Vector EMM = Calculator.multiply(data.getMM(), data.getE()); // E*MM
        return Calculator.add(BMC, Calculator.add(DMZ, EMM)); // A
    }

    public Matrix calculateMA() {
        Vector DB = Calculator.add(data.getD(), data.getB()); // D+B
        Scalar maxDB = Calculator.max(DB); // max(D+B)
        Matrix MZMM = Calculator.multiply(data.getMZ(), data.getMM()); // MZ*MM
        Matrix maxDBMZMM = Calculator.multiply(MZMM, maxDB); // max(D+B)*MZ*MM
        Matrix MLMC = Calculator.multiply(data.getML(), data.getMC()); // ML*MC
        Matrix MLMCa = Calculator.multiply(MLMC, data.getA()); // ML*MC*a
        return Calculator.subtract(maxDBMZMM, MLMCa); // MA
    }

}
