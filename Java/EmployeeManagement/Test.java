import java.util.Scanner;

public class Test {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        long id;
        int yos, salPerMon;
        String name, dept, desig, progLangs, currProj;

        System.out.print("\nEnter the ID of the employee: ");
        id = input.nextLong();
        input.nextLine();

        System.out.print("\nEnter the name of the employee: ");
        name = input.nextLine();

        System.out.print("\nEnter the department of the employee: ");
        dept = input.nextLine();

        System.out.print("\nEnter the designation of the employee: ");
        desig = input.nextLine();

        System.out.print("\nEnter the years of service of the employee: ");
        yos = input.nextInt();

        System.out.print("\nEnter the monthly salary of the employee: ");
        salPerMon = input.nextInt();
        System.out.print("\n\n");

        Employee E = new Employee(id, yos, salPerMon, name, dept, desig);
        E.Display();

        System.out.print("\nEnter the ID of the developer: ");
        id = input.nextLong();
        input.nextLine();

        System.out.print("\nEnter the name of the developer: ");
        name = input.nextLine();

        System.out.print("\nEnter the department of the developer: ");
        dept = input.nextLine();

        System.out.print("\nEnter the designation of the developer: ");
        desig = input.nextLine();

        System.out.print("\nEnter the years of service of the developer: ");
        yos = input.nextInt();

        System.out.print("\nEnter the monthly salary of the developer: ");
        salPerMon = input.nextInt();

        System.out.print("\nEnter the Programming Language Expertise of the developer: ");
        progLangs = input.nextLine();

        System.out.print("\nEnter the Current project that the developer is working on: ");
        currProj = input.nextLine();
        System.out.print("\n\n");

        Developer D = new Developer(id, yos, salPerMon, name, dept, desig, progLangs, currProj);
        D.Display();

        input.close();
    }
}
