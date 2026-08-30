package railway.main;

import railway.login.LoginService;
import railway.login.User;
import railway.train.TrainEntity;
import railway.train.TrainService;
import railway.booking.BookingService;
import railway.viewcancel.TicketViewer;
import railway.viewcancel.CancellationService;

import java.util.Scanner;

public class RailwayReservation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Create default user for demo
        User defaultUser = new User("admin", "password123");
        LoginService loginService = new LoginService(defaultUser);
        
        // Initialize train service with sample trains
        TrainService trainService = new TrainService();
        trainService.addTrain(new TrainEntity("Rajdhani Express", "Delhi", "Mumbai", 50, 30, 20));
        trainService.addTrain(new TrainEntity("Shatabdi Express", "Delhi", "Chennai", 40, 25, 15));
        trainService.addTrain(new TrainEntity("Duronto Express", "Kolkata", "Mumbai", 30, 20, 10));
        trainService.addTrain(new TrainEntity("Garib Rath", "Bangalore", "Hyderabad", 60, 40, 0));
        
        // Create booking service
        BookingService bookingService = new BookingService(trainService);
        
        // Create viewer and cancellation services
        TicketViewer ticketViewer = new TicketViewer(bookingService.getTicketMap());
        CancellationService cancellationService = new CancellationService(bookingService.getTicketMap());
        
        // Login loop
        boolean loggedIn = false;
        while (!loggedIn) {
            System.out.println("====== RAILWAY RESERVATION SYSTEM ======");
            System.out.print("Username: ");
            String username = scanner.nextLine();
            System.out.print("Password: ");
            String password = scanner.nextLine();
            
            if (loginService.login(username, password)) {
                System.out.println("Login successful!\n");
                loggedIn = true;
            } else {
                System.out.println("Invalid credentials! Please try again.\n");
            }
        }
        
        // Main menu loop
        boolean exit = false;
        while (!exit) {
            System.out.println("====== RAILWAY MENU ======");
            System.out.println("1. Search Train");
            System.out.println("2. Book Ticket");
            System.out.println("3. View Ticket");
            System.out.println("4. Cancel Ticket");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            
            String choice = scanner.nextLine();
            
            switch (choice) {
                case "1":
                    searchTrain(trainService, scanner);
                    break;
                case "2":
                    bookingService.bookTicket();
                    break;
                case "3":
                    viewTicket(ticketViewer, scanner);
                    break;
                case "4":
                    cancelTicket(cancellationService, scanner);
                    break;
                case "5":
                    exit = true;
                    System.out.println("Thank you for using Railway Reservation System!");
                    break;
                default:
                    System.out.println("Invalid choice! Please try again.");
            }
            System.out.println();
        }
        
        scanner.close();
    }
    
    private static void searchTrain(TrainService trainService, Scanner scanner) {
        System.out.print("Enter Source: ");
        String source = scanner.nextLine();
        System.out.print("Enter Destination: ");
        String destination = scanner.nextLine();
        
        var trains = trainService.searchTrain(source, destination);
        if (trains.isEmpty()) {
            System.out.println("No trains found for this route!");
        } else {
            System.out.println("\nAvailable Trains:");
            for (TrainEntity train : trains) {
                train.displayTrain();
            }
        }
    }
    
    private static void viewTicket(TicketViewer viewer, Scanner scanner) {
        System.out.print("Enter PNR: ");
        String pnr = scanner.nextLine();
        viewer.viewTicket(pnr);
    }
    
    private static void cancelTicket(CancellationService cancellationService, Scanner scanner) {
        System.out.print("Enter PNR: ");
        String pnr = scanner.nextLine();
        cancellationService.cancelTicket(pnr);
    }
}