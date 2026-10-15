import java.io.*;
import java.util.Scanner;

public class TestFileHandling {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter file path (e.g., data.txt): ");
        String filepath = scanner.nextLine().trim();

        FileOperations fileOps = new FileOperations(filepath);

        // Ensure file exists
        fileOps.createNewFile();

        int choice;
        do {
            System.out.println("\n========== FILE HANDLING MENU ==========");
            System.out.println("1. File Read using Byte Stream");
            System.out.println("2. File Write using Byte Stream");
            System.out.println("3. File Read using Character Stream");
            System.out.println("4. File Write using Character Stream");
            System.out.println("5. Append Data to File");
            System.out.println("6. File Info (name, path, size, readable, writable, etc.)");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");

            try {
                choice = Integer.parseInt(scanner.nextLine().trim());
            } catch (NumberFormatException e) {
                choice = -1;
            }

            String inputData;
            switch (choice) {
                case 1:
                    fileOps.readByteFile();
                    break;
                case 2:
                    System.out.print("Enter data to write (byte stream): ");
                    inputData = scanner.nextLine();
                    fileOps.writeByteFile(inputData);
                    break;
                case 3:
                    fileOps.readCharacterFile();
                    break;
                case 4:
                    System.out.print("Enter data to write (character stream): ");
                    inputData = scanner.nextLine();
                    fileOps.writeCharacterFile(inputData);
                    break;
                case 5:
                    System.out.print("Enter data to append: ");
                    inputData = scanner.nextLine();
                    fileOps.appendDataFile(inputData);
                    break;
                case 6:
                    fileOps.displayFileInfo();
                    break;
                case 0:
                    System.out.println("Exiting... Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please select 0-6.");
            }
        } while (choice != 0);

        scanner.close();
    }
}