import java.util.Scanner;

public class Employee {
    long employeeId;
    String employeeName;
    String department;
    int yearsOfService;
    double basicSalary;

    public Employee() {}

    public Employee(long id, String name, String dept, int years, double basicSalary) {
        this.employeeId = id;
        this.employeeName = name;
        this.department = dept;
        this.yearsOfService = years;
        this.basicSalary = basicSalary;
    }

    public void addEmployee(Scanner input) {
        System.out.print("Enter Employee ID: ");
        this.employeeId = input.nextLong();
        input.nextLine();

        System.out.print("Enter Employee Name: ");
        this.employeeName = input.nextLine();

        System.out.print("Enter Department: ");
        this.department = input.nextLine();

        System.out.print("Enter Years of Service: ");
        this.yearsOfService = input.nextInt();

        System.out.print("Enter Basic Salary: ");
        this.basicSalary = input.nextDouble();
        input.nextLine();
    }

    public double calculateSalary() {
        double allowance = 0.20 * basicSalary;
        double increments = yearsOfService * (0.07 * basicSalary);
        return basicSalary + allowance + increments;
    }

    public void display() {
        System.out.println("ID: " + employeeId);
        System.out.println("Name: " + employeeName);
        System.out.println("Department: " + department);
        System.out.println("Years of Service: " + yearsOfService);
        System.out.println("Basic Salary: $" + basicSalary);
        System.out.println("Total Calculated Salary: $" + calculateSalary());
    }
}

class Manager extends Employee {
    int teamSize;
    String level;

    public Manager() {}

    public Manager(long id, String name, String dept, int years, double basicSalary, int teamSize, String level) {
        super(id, name, dept, years, basicSalary);
        this.teamSize = teamSize;
        this.level = level;
    }

    @Override
    public void addEmployee(Scanner input) {
        super.addEmployee(input);
        System.out.print("Enter Team Size: ");
        this.teamSize = input.nextInt();
        input.nextLine();

        System.out.print("Enter Manager Level: ");
        this.level = input.nextLine();
    }

    public void assignTask(String task) {
        System.out.println("Manager " + employeeName + " assigned task: " + task);
    }

    @Override
    public double calculateSalary() {
        double baseCalculatedSalary = super.calculateSalary();
        double bonus = teamSize * (0.03 * basicSalary);
        return baseCalculatedSalary + bonus;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Team Size: " + teamSize);
        System.out.println("Manager Level: " + level);
    }
}

class SeniorManager extends Manager {
    int numberOfTeams;
    String projectType;

    public SeniorManager() {}

    public SeniorManager(long id, String name, String dept, int years, double basicSalary, int teamSize, String level, int numberOfTeams, String projectType) {
        super(id, name, dept, years, basicSalary, teamSize, level);
        this.numberOfTeams = numberOfTeams;
        this.projectType = projectType;
    }

    @Override
    public void addEmployee(Scanner input) {
        super.addEmployee(input);
        System.out.print("Enter Number of Teams: ");
        this.numberOfTeams = input.nextInt();
        input.nextLine();

        System.out.print("Enter Project Type: ");
        this.projectType = input.nextLine();
    }

    public void allocateBudget(double amount) {
        System.out.println("Senior Manager " + employeeName + " allocated $" + amount + " to project " + projectType);
    }

    @Override
    public double calculateSalary() {
        return super.calculateSalary();
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Number of Teams Managed: " + numberOfTeams);
        System.out.println("Project Type: " + projectType);
    }
}

class Developer extends Employee {
    String languageSkills;
    String level;

    public Developer() {}

    public Developer(long id, String name, String dept, int years, double basicSalary, String languageSkills, String level) {
        super(id, name, dept, years, basicSalary);
        this.languageSkills = languageSkills;
        this.level = level;
    }

    @Override
    public void addEmployee(Scanner input) {
        super.addEmployee(input);
        System.out.print("Enter Language/Skills (C / CPP / Java / Python): ");
        this.languageSkills = input.nextLine();

        System.out.print("Enter Developer Level (Junior / Mid / Senior): ");
        this.level = input.nextLine();
    }

    public void writeCode() {
        System.out.println("Developer " + employeeName + " is writing code in " + languageSkills);
    }

    @Override
    public double calculateSalary() {
        double baseCalculatedSalary = super.calculateSalary();
        double certBonusRate = 0.0;

        if (languageSkills.equalsIgnoreCase("C")) {
            certBonusRate = 0.02;
        } else if (languageSkills.equalsIgnoreCase("CPP") || languageSkills.equalsIgnoreCase("C++")) {
            certBonusRate = 0.03;
        } else if (languageSkills.equalsIgnoreCase("Java") || languageSkills.equalsIgnoreCase("Python")) {
            certBonusRate = 0.05;
        }

        double certificationBonus = certBonusRate * basicSalary;
        return baseCalculatedSalary + certificationBonus;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Language/Skills: " + languageSkills);
        System.out.println("Developer Level: " + level);
    }
}