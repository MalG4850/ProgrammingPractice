public class Student {
    enum Year { FY, SY, TY, BTech }

    long prn;
    String name;
    Year year;
    String department;
    String division;
    long mobile;
    double percentage;

    Student() {
        this.prn = 0;
        this.name = "";
        this.year = Year.FY;
        this.department = "";
        this.division = "";
        this.mobile = 0;
        this.percentage = 0.0;
    }

    Student(long prn, String name) {
        this.prn = prn;
        this.name = name;
        this.year = Year.FY;
        this.department = "";
        this.division = "";
        this.mobile = 0;
        this.percentage = 0.0;
    }

    Student(long prn, String name, Year year, String department, String division, long mobile, double percentage) {
        this.prn = prn;
        this.name = name;
        this.year = year;
        this.department = department;
        this.division = division;
        this.mobile = mobile;
        this.percentage = percentage;
    }

    @Override
    public String toString() {
        return "Student [PRN=" + prn + ", Name=" + name + ", Year=" + year +
               ", Department=" + department + ", Division=" + division +
               ", Mobile=" + mobile + ", Percentage=" + percentage + "]";
    }
}
