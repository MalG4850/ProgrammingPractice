import java.util.Scanner;

public class typeConversion {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("\nEnter a decimal number: ");
        double d = input.nextDouble();
        int i = (int) d;
        System.out.print(
            "\nDouble: " + d + "\nand the truncated Integer: " + i + "\n\n"
        );
        input.close();
    }
}
