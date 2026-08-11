import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("================ Add Regular Employee ================");
        Employee emp = new Employee();
        emp.addEmployee(input);

        System.out.println("\n================ Add Developer ================");
        Developer dev = new Developer();
        dev.addEmployee(input);

        System.out.println("\n================ Add Senior Manager ================");
        SeniorManager sm = new SeniorManager();
        sm.addEmployee(input);

        System.out.println("\n\n**************** DISPLAYING RECORDS ****************\n");

        System.out.println("--- Regular Employee Details ---");
        emp.display();

        System.out.println("\n--- Developer Details ---");
        dev.display();
        dev.writeCode();

        System.out.println("\n--- Senior Manager Details ---");
        sm.display();
        sm.assignTask("System Refactoring");
        sm.allocateBudget(150000);

        input.close();
    }
}