import java.util.Scanner;

public class TestApp {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HospitalDAO dao = new HospitalDAO();

        try {
            dao.createConnection();
            System.out.println("Database Connected Successfully!");
        } catch (Exception e) {
            System.out.println("Database Connection Failed! Check your credentials.");
            return;
        }

        int choice;
        do {
            System.out.println("\n========== Hospital Management System ==========");
            System.out.println("1. Add Patient");
            System.out.println("2. View Patients");
            System.out.println("3. Update Patient Disease");
            System.out.println("4. Delete Patient");
            System.out.println("5. Book Appointment");
            System.out.println("6. Exit");
            System.out.print("Select appropriate option: ");

            try {
                choice = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Please enter a number between 1 and 6.");
                choice = 0;
                continue;
            }

            switch (choice) {
                case 1:
                    System.out.print("Enter Name: ");
                    String name = scanner.nextLine();
                    System.out.print("Enter Age: ");
                    int age = Integer.parseInt(scanner.nextLine());
                    System.out.print("Enter Gender: ");
                    String gender = scanner.nextLine();
                    System.out.print("Enter Disease: ");
                    String disease = scanner.nextLine();
                    System.out.print("Enter Appointment Time (e.g., 2026-06-10 10:30 AM): ");
                    String appointment = scanner.nextLine();

                    Patient newPatient = new Patient(name, age, gender, disease, appointment);
                    dao.addPatient(newPatient);
                    break;

                case 2:
                    dao.viewPatient();
                    break;

                case 3:
                    System.out.print("Enter Patient ID to update: ");
                    int updateId = Integer.parseInt(scanner.nextLine());
                    System.out.print("Enter New Disease: ");
                    String newDisease = scanner.nextLine();
                    dao.updatePatient(updateId, newDisease);
                    break;

                case 4:
                    System.out.print("Enter Patient ID to delete: ");
                    int deleteId = Integer.parseInt(scanner.nextLine());
                    dao.deletePatient(deleteId);
                    break;

                case 5:
                    System.out.print("Enter Patient ID to book appointment: ");
                    int appId = Integer.parseInt(scanner.nextLine());
                    System.out.print("Enter Appointment Details/Time: ");
                    String appTime = scanner.nextLine();
                    dao.bookAppointment(appId, appTime);
                    break;

                case 6:
                    System.out.println("Exiting application. Goodbye!");
                    break;

                default:
                    System.out.println("Invalid option! Please choose between 1 and 6.");
            }
        } while (choice != 6);

        scanner.close();
    }
}
