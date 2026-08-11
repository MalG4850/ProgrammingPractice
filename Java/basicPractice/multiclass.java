import java.util.Scanner;

class primeNumChecker {

    public static boolean isPrime(int num) {
        if (num == 1 || num == 0) {
            System.out.print(
                "\n" + num + " is neither a prime nor a composite number."
            );
            return false;
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }

        return true;
    }
}

class oddEvenChecker {

    public static boolean Even(int num) {
        if (num % 2 != 0) return false;
        else return true;
    }
}

public class multiclass {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        primeNumChecker p = new primeNumChecker();
        oddEvenChecker o = new oddEvenChecker();

        System.out.print(
            "\nThis is a program to check if an integer is prime/composite, as well as even/odd.\n\n"
        );
        System.out.print("Enter the number: ");
        int num = input.nextInt();

        if (p.isPrime(num)) System.out.printf("\n%d is a prime number ", num);
        else System.out.printf("\n%d is a composite number ", num);

        if (o.Even(num)) System.out.printf("and an even number.\n\n");
        else System.out.printf("and an odd number.\n\n");

        input.close();
    }
}
