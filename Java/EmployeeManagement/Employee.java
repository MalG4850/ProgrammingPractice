public class Employee {
    long id;
    int YearsOfService, SalaryPerMonth;
    String Name, Department, Designation;

    Employee(long id, int yearsofservice, int salary, String name, String department, String designation) {
        this.id = id;
        this.YearsOfService = yearsofservice;
        this.SalaryPerMonth = salary;
        this.Name = name;
        this.Department = department;
        this.Designation = designation;
    }

    void Display() {
        System.out.print("================Employee Info================\n\n");
        System.out.printf(
            "ID: %d\nName: %s\nDepartment: %s\nDesignation: %s\nYears of Service: %d\nSalary per month: %d\n",
            id, Name, Department, Designation, YearsOfService, SalaryPerMonth
        );
    }
}

class Developer extends Employee {
    String ProgrammingLanguages, CurrentProject;

    Developer(long id, int yearsofservice, int salary, String name, String department, String designation, String programminglanguages, String currentproject) {
        super(id, yearsofservice, salary, name, department, designation);
        this.ProgrammingLanguages = programminglanguages;
        this.CurrentProject = currentproject;
    }

    @Override
    void Display() {
        super.Display();
        System.out.printf("Programming Languages: %s\nCurrent Project: %s\n",
            ProgrammingLanguages, CurrentProject);
    }
}
