package booking;
import exception.SeatBookingException;

public class BookingThread extends Thread {
    private BookingSystem bookingSystem;
    private String user;
    private int seats;

    public BookingThread(BookingSystem bookingSystem, String user, int seats) {
        this.bookingSystem = bookingSystem;
        this.user = user;
        this.seats = seats;
    }

    @Override
    public void run() {
        try {
            bookingSystem.bookSeats(user, seats);
        } catch (SeatBookingException e) {
            System.err.println("[Thread Exception] " + e.getMessage());
        }
    }
}
