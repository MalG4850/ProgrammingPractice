public class Motorcycle implements Vehicle {
    double speed;
    String fuelType;

    @Override
    public void start() {
        System.out.print("\nStarted Motorcycle.\n\n");
    }

    @Override
    public void stop() {
        System.out.print("\nStopped Motorcycle.\n\n");
    }

    @Override
    public void getTopSpeed() {
        System.out.printf("\nCurrent Speed: %f", speed);
    }

    @Override
    public void getFuelType() {
        System.out.printf("\nFuel Type: %s", fuelType);
    }
}
