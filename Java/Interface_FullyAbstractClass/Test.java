import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        Car c = new Car();
        Bus b = new Bus();
        Motorcycle m = new Motorcycle();

        System.out.print("What fuel does the car use? ");
        c.fuelType = input.nextLine();

        System.out.print("What fuel does the bus use? ");
        b.fuelType = input.nextLine();

        System.out.print("What fuel does the motorcycle use? ");
        m.fuelType = input.nextLine();

        System.out.print("What is the car's top speed? ");
        c.speed = input.nextDouble();

        System.out.print("What is the bus' top speed? ");
        b.speed = input.nextDouble();

        System.out.print("What is the motorcycle's top speed? ");
        m.speed = input.nextDouble();

        c.start();
        c.stop();
        c.getTopSpeed();
        c.getFuelType();
        c.performMaintenance();

        b.start();
        b.stop();
        b.getTopSpeed();
        b.getFuelType();
        b.performMaintenance();

        m.start();
        m.stop();
        m.getTopSpeed();
        m.getFuelType();

        input.close();
    }
}
