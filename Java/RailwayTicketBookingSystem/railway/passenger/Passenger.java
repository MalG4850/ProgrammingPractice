package railway.passenger;

public class Passenger {
    private String passengerName;
    private Integer age;
    private String gender;
    private String phoneNumber;
    private String berthPreference;

    public Passenger(String passengerName, Integer age, String gender, 
                     String phoneNumber, String berthPreference) {
        this.passengerName = passengerName;
        this.age = age;
        this.gender = gender;
        this.phoneNumber = phoneNumber;
        this.berthPreference = berthPreference;
    }

    public String getPassengerName() {
        return passengerName;
    }

    public Integer getAge() {
        return age;
    }

    public String getGender() {
        return gender;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public String getBerthPreference() {
        return berthPreference;
    }

    public void displayPassenger() {
        System.out.println("Passenger: " + passengerName);
        System.out.println("Age: " + age + ", Gender: " + gender);
        System.out.println("Phone: " + phoneNumber + ", Berth Preference: " + berthPreference);
    }
}