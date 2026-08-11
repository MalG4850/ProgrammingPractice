import java.util.Scanner;

public class primeNum2 {

    static void allPrimes(int n) {
        System.out.print("\nList: ");
        for (int i = 2; i <= n; i++) {
            boolean isPrime = true;

            for (int j = 2; j <= Math.sqrt(i); j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime) {
                System.out.printf("%d ", i);
            }
        }
        System.out.print("\n\n");
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("\nEnter a number to see all prime numbers till it: ");
        int n = input.nextInt();
        allPrimes(n);

        input.close();
    }
}
