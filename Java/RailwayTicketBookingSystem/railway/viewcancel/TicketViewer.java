package railway.viewcancel;

import railway.booking.Ticket;

import java.util.HashMap;

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
            System.out.println("No ticket found with PNR: " + pnr);
        }
    }
}