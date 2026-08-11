import java.util.Scanner;

public class primeNum {

    public static boolean isPrime(int num) {
        if (num == 1 || num == 0) {
            System.out.print(
                "\n" + num + " is neither a prime nor a composite number."
            );
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("\nThis is a program to check prime numbers.\n\n");
        System.out.print("Enter the number: ");
        int num = input.nextInt();

        if (isPrime(num)) System.out.print(
            "\n" + num + " is a prime number.\n\n"
        );
        else System.out.print("\n" + num + " is not a prime number.\n\n");
        input.close();
    }
}
