package railway.booking;

import java.util.Random;

public class PNRGenerator {
    public static String generatePNR() {
        Random random = new Random();
        // Generates a 6-digit random PNR number
        Integer pnrNum = 100000 + random.nextInt(900000);
        return "PNR" + pnrNum.toString();
    }
}
