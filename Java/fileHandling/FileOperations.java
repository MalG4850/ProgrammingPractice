import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;

public class FileOperations {
    private String filepath;

    public FileOperations(String filepath) {
        this.filepath = filepath;
    }

    public void createNewFile() {
        try {
            File file = new File(filepath);
            if (file.createNewFile()) {
                System.out.println("File created: " + file.getAbsolutePath());
            } else {
                System.out.println("File already exists: " + file.getAbsolutePath());
            }
        } catch (IOException e) {
            System.err.println("Error creating file: " + e.getMessage());
        }
    }

    public void readByteFile() {
        try (FileInputStream fis = new FileInputStream(filepath)) {
            int data;
            System.out.println("\n--- File content (byte stream) ---");
            while ((data = fis.read()) != -1) {
                System.out.print((char) data);
            }
            System.out.println("\n--- End of file ---");
        } catch (FileNotFoundException e) {
            System.err.println("File not found: " + e.getMessage());
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }
    }

    public void writeByteFile(String data) {
        try (FileOutputStream fos = new FileOutputStream(filepath)) {
            fos.write(data.getBytes());
            System.out.println("Data written to file using byte stream.");
        } catch (IOException e) {
            System.err.println("Error writing file: " + e.getMessage());
        }
    }

    public void readCharacterFile() {
        try (FileReader fr = new FileReader(filepath);
             BufferedReader br = new BufferedReader(fr)) {
            String line;
            System.out.println("\n--- File content (character stream) ---");
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
            System.out.println("--- End of file ---");
        } catch (FileNotFoundException e) {
            System.err.println("File not found: " + e.getMessage());
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }
    }

    public void writeCharacterFile(String data) {
        try (FileWriter fw = new FileWriter(filepath);
             BufferedWriter bw = new BufferedWriter(fw)) {
            bw.write(data);
            System.out.println("Data written to file using character stream.");
        } catch (IOException e) {
            System.err.println("Error writing file: " + e.getMessage());
        }
    }

    public void appendDataFile(String data) {
        try (FileWriter fw = new FileWriter(filepath, true);
             BufferedWriter bw = new BufferedWriter(fw)) {
            bw.newLine(); // ensure new line before appended data
            bw.write(data);
            System.out.println("Data appended to file.");
        } catch (IOException e) {
            System.err.println("Error appending to file: " + e.getMessage());
        }
    }

    public void displayFileInfo() {
        File file = new File(filepath);
        System.out.println("\n=== File Information ===");
        System.out.println("Name        : " + file.getName());
        System.out.println("Absolute Path: " + file.getAbsolutePath());
        System.out.println("Size (bytes): " + file.length());
        System.out.println("Readable    : " + file.canRead());
        System.out.println("Writable    : " + file.canWrite());
        System.out.println("Exists      : " + file.exists());
        System.out.println("Is File     : " + file.isFile());
        System.out.println("Is Directory: " + file.isDirectory());
        System.out.println("Last Modified: " + new java.util.Date(file.lastModified()));
        System.out.println("==========================");
    }
}
