package railway.login;

import java.util.Scanner;

public class LoginService {
    private User user;

    public LoginService() {
        // Default system user credentials
        this.user = new User("admin", "1234");
    }

    public Boolean verifyUser(String username, String password) {
        // Wrapper class Boolean return type
        if (user.getUsername().equals(username) && user.getPassword().equals(password)) {
            return Boolean.TRUE;
        }
        return Boolean.FALSE;
    }

    public Boolean login() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("\n========== USER LOGIN ==========");
        System.out.print("Enter Username: ");
        String inputUser = scanner.nextLine();
        System.out.print("Enter Password: ");
        String inputPass = scanner.nextLine();

        if (verifyUser(inputUser, inputPass)) {
            System.out.println("Login Successful!\n");
            return true;
        } else {
            System.out.println("Invalid Credentials! Please try again.\n");
            return false;
        }
    }
}
