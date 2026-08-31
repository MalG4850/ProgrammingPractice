package railway.booking;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import railway.passenger.Passenger;
import railway.train.TrainEntity;
import railway.train.TrainService;

public class BookingService {
    private TrainService trainService;
    private HashMap<String, Ticket> ticketMap;

    public BookingService(TrainService trainService, HashMap<String, Ticket> ticketMap) {
        this.trainService = trainService;
        this.ticketMap = ticketMap;
    }

    public void bookTicket() {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter Source Station: ");
        String source = sc.nextLine();
        System.out.print("Enter Destination Station: ");
        String dest = sc.nextLine();

        ArrayList<TrainEntity> matchedTrains = trainService.searchTrain(source, dest);

        if (matchedTrains.size() == 0) {
            System.out.println("No trains found for this route!\n");
            return;
        }

        System.out.println("\nMatching Trains Found:");
        for (int i = 0; i < matchedTrains.size(); i++) {
            System.out.print("[" + (i + 1) + "] ");
            matchedTrains.get(i).displayTrain();
        }

        System.out.print("Select Train (Enter Number): ");
        int choice = sc.nextInt();
        sc.nextLine(); // clear buffer

        if (choice < 1 || choice > matchedTrains.size()) {
            System.out.println("Invalid selection!");
            return;
        }

        TrainEntity selectedTrain = matchedTrains.get(choice - 1);

        // Passenger Details Input
        System.out.print("Enter Passenger Name: ");
        String name = sc.nextLine();
        System.out.print("Enter Age: ");
        Integer age = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter Gender: ");
        String gender = sc.nextLine();
        System.out.print("Enter Phone Number: ");
        String phone = sc.nextLine();
        System.out.print("Enter Berth Preference (Lower/Upper/Side): ");
        String berth = sc.nextLine();

        Passenger passenger = new Passenger(name, age, gender, phone, berth);

        System.out.print("Select Class (Seating/Sleeper/AC): ");
        String bookingClass = sc.nextLine();

        String pnr = PNRGenerator.generatePNR();
        Integer seatNum = (int)(Math.random() * 60) + 1; // Random seat allocation

        Ticket ticket = new Ticket(pnr, selectedTrain, passenger, bookingClass, seatNum);
        ticket.book();
        saveTicket(ticket);

        System.out.println("\nBooking Confirmed! Generated PNR: " + pnr + "\n");
    }

    public void saveTicket(Ticket ticket) {
        ticketMap.put(ticket.getPnr(), ticket);
    }

    public Ticket getTicket(String pnr) {
        return ticketMap.get(pnr);
    }

    public void displayBookingDetails() {
        System.out.println("Total active bookings stored in memory: " + ticketMap.size());
    }
}
