package booking;
import exception.SeatBookingException;

public class BookingRunnable implements Runnable {
    private BookingSystem bookingSystem;
    private String user;
    private int seats;

    public BookingRunnable(BookingSystem bookingSystem, String user, int seats) {
        this.bookingSystem = bookingSystem;
        this.user = user;
        this.seats = seats;
    }

    @Override
    public void run() {
        try {
            bookingSystem.bookSeats(user, seats);
        } catch (SeatBookingException e) {
            System.err.println("[Runnable Exception] " + e.getMessage());
        }
    }
}
