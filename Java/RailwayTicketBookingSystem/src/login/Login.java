package login;
import java.io.Console;
import java.util.Scanner;

public class Login {
    Scanner input = new Scanner(System.in);
    private final String username = "testUser", password = "test@123";
    Console console = System.console();

    public Login() {
        if (console == null) {
            System.out.println("Error: Console not available. Please run this from a standard command line.");
            System.exit(1);
        }
    }

    void acceptUserLogin() {
        System.out.print("\nEnter your Username: ");
        String uname = input.nextLine();

        char[] passwdChars = console.readPassword("Enter your password: ");
        String passwd = new String(passwdChars);
        java.util.Arrays.fill(passwdChars, ' ');

        System.out.println("Password received successfully!");

        validateUserLogin(uname, passwd);
    }

    void validateUserLogin(String uname, String passwd) {
        if (username.compareTo(uname) == 0 && password.compareTo(passwd) == 0) {
            System.out.print("\nLogin Successful!\n\n");
        } else System.out.print("\nError: Password Mismatch!\n\n");
    }
}