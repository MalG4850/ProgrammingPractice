package railway.viewcancel;

import java.util.HashMap;
import java.util.Scanner;
import railway.booking.Ticket;

public class CancellationService {
    private HashMap<String, Ticket> ticketMap;

    public CancellationService(HashMap<String, Ticket> ticketMap) {
        this.ticketMap = ticketMap;
    }

    public void cancelTicket(String pnr) {
        Ticket ticket = ticketMap.get(pnr);
        if (ticket == null) {
            System.out.println("Cannot cancel. Invalid or non-existent PNR: " + pnr + "\n");
            return;
        }

        if (ticket.getBookingStatus().equals("CANCELLED")) {
            System.out.println("This ticket is already cancelled!\n");
            return;
        }

        Scanner sc = new Scanner(System.in);
        System.out.print("Are you sure you want to cancel ticket " + pnr + "? (yes/no): ");
        String confirm = sc.nextLine();

        if (confirm.equalsIgnoreCase("yes")) {
            ticket.cancel();
            System.out.println("Cancellation confirmed for PNR " + pnr + ".\n");
        } else {
            System.out.println("Cancellation operation aborted.\n");
        }
    }
}
