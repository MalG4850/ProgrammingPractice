import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Create Student object using default constructor
        Student s1 = new Student();
        System.out.println("Default constructor object: " + s1);

        // Accept PRN and name for parameterized constructor (id, name)
        System.out.print("\nEnter PRN: ");
        long prn = input.nextLong();
        input.nextLine();
        System.out.print("Enter Name: ");
        String name = input.nextLine();

        // Create Student object using parameterized constructor (id, name)
        Student s2 = new Student(prn, name);
        System.out.println("Parameterized constructor (id, name) object: " + s2);

        // Accept remaining values for full parameterized constructor
        System.out.print("\nEnter Year (FY/SY/TY/BTech): ");
        Student.Year year = Student.Year.valueOf(input.next().toUpperCase());

        System.out.print("Enter Department: ");
        String department = input.next();

        System.out.print("Enter Division: ");
        String division = input.next();

        System.out.print("Enter Mobile: ");
        long mobile = input.nextLong();

        System.out.print("Enter Percentage: ");
        double percentage = input.nextDouble();

        // Create Student object using parameterized constructor (all attributes)
        Student s3 = new Student(prn, name, year, department, division, mobile, percentage);
        System.out.println("\nAll objects displayed:");
        System.out.println("s1 (default): " + s1);
        System.out.println("s2 (id, name): " + s2);
        System.out.println("s3 (all): " + s3);

        input.close();
    }
}
