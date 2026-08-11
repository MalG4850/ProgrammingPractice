import java.util.Scanner;

public class largestInt {

    static int max(int[] values) {
        int m = values[0];
        for (int i = 0; i < values.length; i++) {
            if (m < values[i]) m = values[i];
            else continue;
        }
        return m;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print(
            "\nThis is a program to find the largest integer in an array.\n\n"
        );
        System.out.print("Enter number of elements: ");
        int n = input.nextInt();
        int[] values = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("\nEnter the element: ");
            values[i] = input.nextInt();
        }
        System.out.print(
            "\nThe largest number in the given set is: " + max(values) + "\n\n"
        );
        input.close();
    }
}
