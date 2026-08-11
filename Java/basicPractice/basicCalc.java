import java.util.Scanner;

public class basicCalc {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print(
            "This is a program for a basic calculator.\n\nOperations:\n\n[1] Addition\n[2] Subtraction\n[3] Multiplication\n[4] Division\n\nEnter choice (1-4): "
        );
        int ch = input.nextInt();

        System.out.print("\nEnter the first number: ");
        float n1 = input.nextFloat();

        System.out.print("\nEnter the second number: ");
        float n2 = input.nextFloat();

        switch (ch) {
            case 1:
                System.out.print(
                    "\n" + n1 + " + " + n2 + " = " + (n1 + n2) + "\n\n"
                );
                break;
            case 2:
                System.out.print(
                    "\n" + n1 + " - " + n2 + " = " + (n1 - n2) + "\n\n"
                );
                break;
            case 3:
                System.out.print(
                    "\n" + n1 + " * " + n2 + " = " + n1 * n2 + "\n\n"
                );
                break;
            case 4:
                System.out.print(
                    "\n" + n1 + " / " + n2 + " = " + n1 / n2 + "\n\n"
                );
                break;
        }

        input.close();
    }
}
