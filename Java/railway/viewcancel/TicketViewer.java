package railway.viewcancel;

import java.util.HashMap;
import railway.booking.Ticket;

public class TicketViewer {
    private HashMap<String, Ticket> ticketMap;

    public TicketViewer(HashMap<String, Ticket> ticketMap) {
        this.ticketMap = ticketMap;
    }

    public void viewTicket(String pnr) {
        Ticket ticket = ticketMap.get(pnr);
        if (ticket != null) {
            ticket.displayTicket();
        } else {
            System.out.println("No booking record found for PNR: " + pnr + "\n");
        }
    }
}
