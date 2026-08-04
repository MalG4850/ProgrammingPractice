public class Car implements Vehicle, Maintenance {
    double speed;
    String fuelType;

    @Override
    public void start() {
        System.out.print("\nStarted Car.\n\n");
    }

    @Override
    public void stop() {
        System.out.print("\nStopped Car.\n\n");
    }

    @Override
    public void getTopSpeed() {
        System.out.printf("\nCurrent Speed: %f", speed);
    }

    @Override
    public void getFuelType() {
        System.out.printf("\nFuel Type: %s", fuelType);
    }

    @Override
    public void performMaintenance() {
        System.out.print("\nPerforming maintenance....\n");
        System.out.print("Done!\n\n");
        System.out.printf("Handling Charges are: %d\n\n", handlingCharges);
    }
}
