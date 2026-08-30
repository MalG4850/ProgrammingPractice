package railway.booking;

import java.util.Random;

public class PNRGenerator {
    private static final Random random = new Random();

    public static String generatePNR() {
        StringBuilder pnr = new StringBuilder();
        for (int i = 0; i < 10; i++) {
            pnr.append(random.nextInt(10));
        }
        return pnr.toString();
    }
}