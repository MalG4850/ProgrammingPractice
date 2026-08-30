package railway.booking;

import java.util.HashMap;
import java.util.List;
import java.util.Scanner;
import railway.passenger.Passenger;
import railway.train.TrainEntity;
import railway.train.TrainService;

public class BookingService {
    private TrainService trainService;
    private HashMap<String, Ticket> ticketMap;
    private Scanner scanner;

    public BookingService(TrainService trainService) {
        this.trainService = trainService;
        this.ticketMap = new HashMap<>();
        this.scanner = new Scanner(System.in);
    }

    public void bookTicket() {
        System.out.print("Enter Source: ");
        String source = scanner.nextLine();
        
        System.out.print("Enter Destination: ");
        String destination = scanner.nextLine();

        List<TrainEntity> trains = trainService.searchTrain(source, destination);
        
        if (trains.isEmpty()) {
            System.out.println("No trains found for this route!");
            return;
        }

        System.out.println("\nAvailable Trains:");
        for (int i = 0; i < trains.size(); i++) {
            System.out.print((i + 1) + ". ");
            trains.get(i).displayTrain();
        }

        System.out.print("Select Train (1-" + trains.size() + "): ");
        int trainChoice = Integer.parseInt(scanner.nextLine());
        
        if (trainChoice < 1 || trainChoice > trains.size()) {
            System.out.println("Invalid selection!");
            return;
        }

        TrainEntity selectedTrain = trains.get(trainChoice - 1);

        System.out.print("Enter Passenger Name: ");
        String pName = scanner.nextLine();
        
        System.out.print("Enter Age: ");
        Integer age = scanner.nextInt();
        
        System.out.print("Enter Gender: ");
        String gender = scanner.nextLine();
        
        System.out.print("Enter Phone Number: ");
        String phone = scanner.nextLine();
        
        System.out.print("Enter Berth Preference: ");
        String berth = scanner.nextLine();

        Passenger passenger = new Passenger(pName, age, gender, phone, berth);

        System.out.println("Select Class: 1. Seating  2. Sleeper  3. AC");
        System.out.print("Choice: ");
        int classChoice = Integer.parseInt(scanner.nextLine());
        
        String bookingClass;
        Integer availableSeats;
        
        switch (classChoice) {
            case 1 -> {
                bookingClass = "SEATING";
                availableSeats = selectedTrain.getSeating();
            }
            case 2 -> {
                bookingClass = "SLEEPER";
                availableSeats = selectedTrain.getSleeper();
            }
            case 3 -> {
                bookingClass = "AC";
                availableSeats = selectedTrain.getAc();
            }
            default -> {
                System.out.println("Invalid class selection!");
                return;
            }
        }

        if (availableSeats <= 0) {
            System.out.println("No seats available in this class!");
            return;
        }

        String pnr = PNRGenerator.generatePNR();
        Integer seatNumber = availableSeats; // simple assignment
        
        // Decrement available seats
        switch (classChoice) {
            case 1 -> selectedTrain.decrementSeating();
            case 2 -> selectedTrain.decrementSleeper();
            case 3 -> selectedTrain.decrementAc();
        }

        Ticket ticket = new Ticket(pnr, selectedTrain, passenger, bookingClass, seatNumber, "PENDING");
        ticket.book();
        
        saveTicket(ticket);
        displayBookingDetails(ticket);
    }

    public String generatePNR() {
        return PNRGenerator.generatePNR();
    }

    public void saveTicket(Ticket ticket) {
        ticketMap.put(ticket.getPnr(), ticket);
    }

    public Ticket getTicket(String pnr) {
        return ticketMap.get(pnr);
    }

    public void displayBookingDetails(Ticket ticket) {
        ticket.displayTicket();
    }

    public HashMap<String, Ticket> getTicketMap() {
        return ticketMap;
    }
}