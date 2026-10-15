public class Patient {
    private int id;
    private String name;
    private int age;
    private String gender;
    private String disease;
    private String appointment;

    // Constructors
    public Patient() {}

    public Patient(String name, int age, String gender, String disease, String appointment) {
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.disease = disease;
        this.appointment = appointment;
    }

    public Patient(int id, String name, int age, String gender, String disease, String appointment) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.disease = disease;
        this.appointment = appointment;
    }

    // Getters and Setters
    public int getId() { return id; }
    public void setId(int id) { this.id = id; }

    public String getName() { return name; }
    public void setName(String name) { this.name = name; }

    public int getAge() { return age; }
    public void setAge(int age) { this.age = age; }

    public String getGender() { return gender; }
    public void setGender(String gender) { this.gender = gender; }

    public String getDisease() { return disease; }
    public void setDisease(String disease) { this.disease = disease; }

    public String getAppointment() { return appointment; }
    public void setAppointment(String appointment) { this.appointment = appointment; }

    @Override
    public String toString() {
        return "Patient [ID=" + id + ", Name=" + name + ", Age=" + age +
               ", Gender=" + gender + ", Disease=" + disease + ", Appointment=" + appointment + "]";
    }
}
