import model.Data;

public class Program {
    public static void main (String ...args) {
        Data data = Data.getData();
        Local.run(data);
        Global.run(data);
    }
}
