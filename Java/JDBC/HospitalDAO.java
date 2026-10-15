import java.sql.*;

public class HospitalDAO {
    private static final String URL = "jdbc:mysql://localhost:3306/hospital_db";
    private static final String USER = "root";
    private static final String PASSWORD = "root";

    public Connection createConnection() throws SQLException {
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }

    public void addPatient(Patient patient) {
        String sql = "INSERT INTO patients (name, age, gender, disease, appointment) VALUES (?, ?, ?, ?, ?)";
        try (Connection conn = createConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, patient.getName());
            pstmt.setInt(2, patient.getAge());
            pstmt.setString(3, patient.getGender());
            pstmt.setString(4, patient.getDisease());
            pstmt.setString(5, patient.getAppointment());

            pstmt.executeUpdate();
            System.out.println("Patient added successfully!");
        } catch (SQLException e) {
            System.out.println("Error adding patient: " + e.getMessage());
        }
    }

    public void viewPatient() {
        String sql = "SELECT * FROM patients";
        try (Connection conn = createConnection();
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(sql)) {

            System.out.println("\n--- Patient Records ---");
            boolean hasRecords = false;
            while (rs.next()) {
                hasRecords = true;
                System.out.println("ID: " + rs.getInt("id") +
                                   " | Name: " + rs.getString("name") +
                                   " | Age: " + rs.getInt("age") +
                                   " | Gender: " + rs.getString("gender") +
                                   " | Disease: " + rs.getString("disease") +
                                   " | Appointment: " + rs.getString("appointment"));
            }
            if (!hasRecords) {
                System.out.println("No patient records found.");
            }
        } catch (SQLException e) {
            System.out.println("Error viewing patients: " + e.getMessage());
        }
    }

    public void updatePatient(int id, String newDisease) {
        String sql = "UPDATE patients SET disease = ? WHERE id = ?";
        try (Connection conn = createConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, newDisease);
            pstmt.setInt(2, id);

            int rowsAffected = pstmt.executeUpdate();
            if (rowsAffected > 0) {
                System.out.println("Patient updated successfully!");
            } else {
                System.out.println("Patient with ID " + id + " not found.");
            }
        } catch (SQLException e) {
            System.out.println("Error updating patient: " + e.getMessage());
        }
    }

    public void deletePatient(int id) {
        String sql = "DELETE FROM patients WHERE id = ?";
        try (Connection conn = createConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setInt(1, id);
            int rowsAffected = pstmt.executeUpdate();
            if (rowsAffected > 0) {
                System.out.println("Patient deleted successfully!");
            } else {
                System.out.println("Patient with ID " + id + " not found.");
            }
        } catch (SQLException e) {
            System.out.println("Error deleting patient: " + e.getMessage());
        }
    }

    public void bookAppointment(int id, String appointmentTime) {
        String sql = "UPDATE patients SET appointment = ? WHERE id = ?";
        try (Connection conn = createConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, appointmentTime);
            pstmt.setInt(2, id);

            int rowsAffected = pstmt.executeUpdate();
            if (rowsAffected > 0) {
                System.out.println("Appointment booked successfully!");
            } else {
                System.out.println("Patient with ID " + id + " not found.");
            }
        } catch (SQLException e) {
            System.out.println("Error booking appointment: " + e.getMessage());
        }
    }
}
