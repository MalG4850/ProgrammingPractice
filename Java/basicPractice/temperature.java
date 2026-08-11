import java.util.Scanner;

public class temperature {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print(
            "\nThis is a program to convert temperature from °C to °F.\n\n"
        );
        System.out.print("Enter the temperature in °C: ");
        double cTemp = input.nextDouble();

        double fTemp = ((cTemp * 9) / 5) + 32;

        System.out.print(cTemp + "°C is " + fTemp + "°F.\n\n");
        input.close();
    }
}
