package railway.booking;

import railway.train.TrainEntity;
import railway.passenger.Passenger;

public class Ticket extends Reservation {
    private String bookingClass;
    private Integer seatNumber;
    private String bookingStatus;

    public Ticket(String pnr, TrainEntity train, Passenger passenger, 
                  String bookingClass, Integer seatNumber, String bookingStatus) {
        super(pnr, train, passenger);
        this.bookingClass = bookingClass;
        this.seatNumber = seatNumber;
        this.bookingStatus = bookingStatus;
    }

    public String getBookingClass() {
        return bookingClass;
    }

    public Integer getSeatNumber() {
        return seatNumber;
    }

    public String getBookingStatus() {
        return bookingStatus;
    }

    public void setBookingStatus(String bookingStatus) {
        this.bookingStatus = bookingStatus;
    }

    @Override
    public void book() {
        this.bookingStatus = "CONFIRMED";
        System.out.println("Ticket booked successfully!");
    }

    @Override
    public void displayTicket() {
        System.out.println("========== TICKET DETAILS ==========");
        System.out.println("PNR: " + pnr);
        System.out.println("Status: " + bookingStatus);
        System.out.println("Train: " + train.getName());
        System.out.println("Route: " + train.getSource() + " -> " + train.getDestination());
        System.out.println("Passenger: " + passenger.getPassengerName());
        System.out.println("Age: " + passenger.getAge() + ", Gender: " + passenger.getGender());
        System.out.println("Class: " + bookingClass + ", Seat: " + seatNumber);
        System.out.println("====================================");
    }

    @Override
    public void cancel() {
        this.bookingStatus = "CANCELLED";
        System.out.println("Ticket cancelled successfully!");
    }
}