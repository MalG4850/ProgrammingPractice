package railway.booking;

import railway.train.TrainEntity;
import railway.passenger.Passenger;

public abstract class Reservation {
    protected String pnr;
    protected TrainEntity train;
    protected Passenger passenger;

    public Reservation(String pnr, TrainEntity train, Passenger passenger) {
        this.pnr = pnr;
        this.train = train;
        this.passenger = passenger;
    }

    public String getPnr() {
        return pnr;
    }

    public TrainEntity getTrain() {
        return train;
    }

    public Passenger getPassenger() {
        return passenger;
    }

    public abstract void book();
    public abstract void displayTicket();
    public abstract void cancel();
}