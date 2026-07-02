import java.util.Scanner;

public class factorial {

    static long factorial(int num) {
        int fac = 1;
        for (int i = 1; i <= num; i++) {
            fac *= i;
        }
        return fac;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print(
            "\nThis is a program to calculate factorial of a given number: "
        );
        int num = input.nextInt();
        long factorial = factorial(num);
        if (num < 0) {
            System.out.print(
                "\nInput Error: only positive numbers are supported.\n\n"
            );
        } else {
            System.out.print(
                "\nThe factorial of " + num + " is " + factorial + "\n\n"
            );
        }
        input.close();
    }
}
