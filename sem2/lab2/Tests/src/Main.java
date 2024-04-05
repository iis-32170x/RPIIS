import BooleanFounder.BooleanFounder;

public class Main {
    public static void main(String[] args) {
        BooleanFounder booleanFounder = new BooleanFounder("src/Files/import.txt",
                "src/Files/output.txt");

        booleanFounder.getOriginalSet();
        booleanFounder.findBoolean();
    }
}
//{A, B, <C, D>, {E, F}, G}