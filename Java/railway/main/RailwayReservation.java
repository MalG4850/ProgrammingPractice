package railway.main;

import java.util.HashMap;
import java.util.Scanner;
import railway.booking.BookingService;
import railway.booking.Ticket;
import railway.login.LoginService;
import railway.train.TrainService;
import railway.viewcancel.CancellationService;
import railway.viewcancel.TicketViewer;

public class RailwayReservation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Core Shared Data Structures
        HashMap<String, Ticket> sharedTicketMap = new HashMap<String, Ticket>();

        // Service Instantiation
        LoginService loginService = new LoginService();
        TrainService trainService = new TrainService();
        BookingService bookingService = new BookingService(trainService, sharedTicketMap);
        TicketViewer ticketViewer = new TicketViewer(sharedTicketMap);
        CancellationService cancellationService = new CancellationService(sharedTicketMap);

        // Step 1: Authentication Loop
        boolean loggedIn = false;
        while (!loggedIn) {
            loggedIn = loginService.login();
        }

        // Step 2: Main System Loop
        int choice = 0;
        while (choice != 5) {
            System.out.println("========== RAILWAY MENU ==========");
            System.out.println("1. Search Train");
            System.out.println("2. Book Ticket");
            System.out.println("3. View Ticket");
            System.out.println("4. Cancel Ticket");
            System.out.println("5. Exit");
            System.out.print("Enter Choice [1-5]: ");

            if (scanner.hasNextInt()) {
                choice = scanner.nextInt();
                scanner.nextLine(); // Clear newline
            } else {
                System.out.println("Invalid input type! Enter numbers only.\n");
                scanner.nextLine();
                continue;
            }

            switch (choice) {
                case 1:
                    System.out.print("\nEnter Source Station: ");
                    String src = scanner.nextLine();
                    System.out.print("Enter Destination Station: ");
                    String dst = scanner.nextLine();

                    var list = trainService.searchTrain(src, dst);
                    if (list.size() == 0) {
                        System.out.println("No direct trains available on this route.\n");
                    } else {
                        System.out.println("\nAvailable Trains:");
                        for (int i = 0; i < list.size(); i++) {
                            list.get(i).displayTrain();
                        }
                        System.out.println();
                    }
                    break;

                case 2:
                    bookingService.bookTicket();
                    break;

                case 3:
                    System.out.print("\nEnter PNR to View Ticket: ");
                    String viewPnr = scanner.nextLine();
                    ticketViewer.viewTicket(viewPnr);
                    break;

                case 4:
                    System.out.print("\nEnter PNR to Cancel Ticket: ");
                    String cancelPnr = scanner.nextLine();
                    cancellationService.cancelTicket(cancelPnr);
                    break;

                case 5:
                    System.out.println("\nExiting Railway System. Goodbye!");
                    break;

                default:
                    System.out.println("Invalid option! Please enter between 1 and 5.\n");
            }
        }
        scanner.close();
    }
}
