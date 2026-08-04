interface Vehicle {
    void start();
    void stop();
    void getTopSpeed();
    void getFuelType();
}

interface Maintenance {
    int handlingCharges = 500;
    void performMaintenance();
}
