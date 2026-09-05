package booking;
import exception.SeatBookingException;

public class BookingSystem {
    private int availableSeats = 10; // Total available seats

    public synchronized void bookSeats(String user, int seats) throws SeatBookingException {
        System.out.println("\n--- Processing Booking for User: " + user + " ---");
        login(user);
        selectTheatre();
        selectMovie();
        selectShow();
        chooseSeat(user, seats);
        makePayment(user);
        displayTicket(user, seats);
    }

    public void login(String user) {
        System.out.println(user + " logged in successfully.");
    }

    public void selectTheatre() {
        System.out.println("Theatre selected: PVR Cinemas.");
    }

    public void selectMovie() {
        System.out.println("Movie selected: Interstellar.");
    }

    public void selectShow() {
        System.out.println("Showtime selected: 7:00 PM.");
    }

    public void chooseSeat(String user, int seats) throws SeatBookingException {
        System.out.println(user + " requested " + seats + " seats.");
        if (seats > availableSeats) {
            throw new SeatBookingException("Booking Failed for " + user + "! Requested " + seats +
                                         " seats, but only " + availableSeats + " seats available.");
        }
        availableSeats = availableSeats - seats;
        System.out.println("Seats allocated successfully. Remaining seats: " + availableSeats);
    }

    public void makePayment(String user) {
        System.out.println("Payment processed successfully for " + user + ".");
    }

    public void displayTicket(String user, int seats) {
        System.out.println("=== TICKET CONFIRMED FOR " + user + " (" + seats + " Seats) ===");
    }

    public int getAvailableSeats() {
        return availableSeats;
    }
}
