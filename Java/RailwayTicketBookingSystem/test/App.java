package test;
import functionalities.Functionalities;
import java.util.Scanner;
import login.Login;
import menu.Menu;

public class App {
    public static void main(String[] args) {
        Menu menu = new Menu();
        Login login = new Login();
        Functionalities f = new Functionalities();
        Scanner input = new Scanner(System.in);

        menu.displayMenu();
        byte choice = input.nextByte();
    }
}
