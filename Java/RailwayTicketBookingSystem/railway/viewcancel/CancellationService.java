package railway.viewcancel;

import railway.booking.Ticket;

import java.util.HashMap;
import java.util.Scanner;

public class CancellationService {
    private HashMap<String, Ticket> ticketMap;
    private Scanner scanner;

    public CancellationService(HashMap<String, Ticket> ticketMap) {
        this.ticketMap = ticketMap;
        this.scanner = new Scanner(System.in);
    }

    public void cancelTicket(String pnr) {
        Ticket ticket = ticketMap.get(pnr);
        if (ticket == null) {
            System.out.println("No ticket found with PNR: " + pnr);
            return;
        }

        ticket.displayTicket();
        System.out.print("Are you sure you want to cancel this ticket? (yes/no): ");
        String confirm = scanner.nextLine();

        if (confirm.equalsIgnoreCase("yes") || confirm.equalsIgnoreCase("y")) {
            ticket.cancel();
            System.out.println("Ticket with PNR " + pnr + " has been cancelled.");
        } else {
            System.out.println("Cancellation aborted.");
        }
    }
}