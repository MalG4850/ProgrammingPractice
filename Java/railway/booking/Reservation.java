package railway.booking;

import railway.passenger.Passenger;
import railway.train.TrainEntity;

public abstract class Reservation {
    protected String pnr;
    protected TrainEntity train;
    protected Passenger passenger;

    public Reservation(String pnr, TrainEntity train, Passenger passenger) {
        this.pnr = pnr;
        this.train = train;
        this.passenger = passenger;
    }

    public abstract void book();
    public abstract void displayTicket();
    public abstract void cancel();
}
