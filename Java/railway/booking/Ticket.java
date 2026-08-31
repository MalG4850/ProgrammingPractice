package railway.booking;

import railway.passenger.Passenger;
import railway.train.TrainEntity;

public class Ticket extends Reservation {
    private String bookingClass;
    private Integer seatNumber;
    private String bookingStatus;

    public Ticket(String pnr, TrainEntity train, Passenger passenger, String bookingClass, Integer seatNumber) {
        super(pnr, train, passenger);
        this.bookingClass = bookingClass;
        this.seatNumber = seatNumber;
        this.bookingStatus = "CONFIRMED";
    }

    public String getPnr() { return pnr; }
    public String getBookingStatus() { return bookingStatus; }

    @Override
    public void book() {
        this.bookingStatus = "CONFIRMED";
        System.out.println("Ticket processed successfully for PNR: " + pnr);
    }

    @Override
    public void displayTicket() {
        System.out.println("\n---------------- TICKET DETAILS ----------------");
        System.out.println("PNR Status     : " + bookingStatus);
        System.out.println("PNR Number     : " + pnr);
        System.out.println("Train Name     : " + train.getName());
        System.out.println("Route          : " + train.getSource() + " to " + train.getDestination());
        passenger.displayPassenger();
        System.out.println("Booking Class  : " + bookingClass);
        System.out.println("Seat Number    : " + seatNumber);
        System.out.println("------------------------------------------------\n");
    }

    @Override
    public void cancel() {
        this.bookingStatus = "CANCELLED";
        System.out.println("Ticket with PNR " + pnr + " status set to CANCELLED.");
    }
}
