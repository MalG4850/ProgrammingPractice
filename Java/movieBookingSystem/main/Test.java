import java.util.ArrayList;
import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BookingSystem bookingSystem = new BookingSystem();
        ArrayList<Thread> threadList = new ArrayList<Thread>();

        System.out.println("========== Movie Ticket Booking System ==========");
        System.out.println("Total Available Seats: " + bookingSystem.getAvailableSeats());
        System.out.print("Enter total number of users trying to book tickets: ");
        int totalUsers = scanner.nextInt();

        for (int i = 1; i <= totalUsers; i++) {
            System.out.print("\nEnter name for User " + i + ": ");
            String userName = scanner.next();
            System.out.print("Enter seats requested by " + userName + ": ");
            int seatsRequested = scanner.nextInt();

            // Alternate thread creation between Thread class and Runnable interface
            if (i % 2 != 0) {
                BookingThread thread = new BookingThread(bookingSystem, userName, seatsRequested);
                threadList.add(thread);
            } else {
                BookingRunnable runnable = new BookingRunnable(bookingSystem, userName, seatsRequested);
                Thread thread = new Thread(runnable);
                threadList.add(thread);
            }
        }

        System.out.println("\n--- Starting All Booking Threads Simultaneously ---");
        for (int i = 0; i < threadList.size(); i++) {
            threadList.get(i).start();
        }

        // Waiting for all threads to finish execution using join()
        for (int i = 0; i < threadList.size(); i++) {
            try {
                threadList.get(i).join();
            } catch (InterruptedException e) {
                System.out.println("Thread execution interrupted: " + e.getMessage());
            }
        }

        System.out.println("\nFinal Available Seats remaining: " + bookingSystem.getAvailableSeats());
        System.out.println("Booking Process Finished.");
        scanner.close();
    }
}
