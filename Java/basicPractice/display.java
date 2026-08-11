import java.util.Scanner;

public class display {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("\nEnter a character: ");
        char c = input.next().charAt(0);

        System.out.print("\nEnter a word: ");
        String str = input.next();
        input.nextLine();

        System.out.print("\nEnter a sentence: ");
        String s = input.nextLine();

        System.out.printf("\n\nDisplay: %c, %s, %s\n\n", c, str, s);

        input.close();
    }
}
