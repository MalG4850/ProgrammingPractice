import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Int
        System.out.print("\nEnter an integer: ");
        int x = input.nextInt();
        System.out.printf("\nValue of taken integer: %d\n\n", x);

        Integer y = x;
        System.out.print("Created Object 'y' of Wrapper Class 'Integer'. Value: " + y + "\n\n");

        int z = y.intValue();
        System.out.print("Made an int variable 'z' with y.intValue() function.\n\n");

        System.out.print("The value of z = " + z + "\n\n");


        // Float
        System.out.print("\nEnter a float: ");
        float a = input.nextFloat();
        System.out.printf("\nValue of taken float: %f\n\n", a);

        Float b = a;
        System.out.print("Created Object 'y' of Wrapper Class 'Float'. Value: " + b + "\n\n");

        float c = b.floatValue();
        System.out.print("Made an float variable 'z' with y.floatValue() function.\n\n");

        System.out.print("The value of z = " + c + "\n\n");


        // Double
        System.out.print("\nEnter a double: ");
        double d = input.nextDouble();
        System.out.printf("\nValue of taken double: %f\n\n", d);

        Double e = d;
        System.out.print("Created Object 'y' of Wrapper Class 'Double'. Value: " + e + "\n\n");

        double f = e.doubleValue();
        System.out.print("Made an double variable 'z' with y.doubleValue() function.\n\n");

        System.out.print("The value of z = " + f + "\n\n");


        // Char
        System.out.print("\nEnter a character: ");
        char g = input.next().charAt(0);
        System.out.printf("\nValue of taken character: %c\n\n", g);

        Character h = g;
        System.out.print("Created Object 'y' of Wrapper Class 'Character'. Value: " + h + "\n\n");

        char i = h.charValue();
        System.out.print("Made an char variable 'z' with y.charValue() function.\n\n");

        System.out.print("The value of z = " + i + "\n\n");


        // Short
        System.out.print("\nEnter a short int: ");
        short j = input.nextShort();
        System.out.printf("\nValue of taken short int: %d\n\n", j);

        Short k = j;
        System.out.print("Created Object 'y' of Wrapper Class 'Short'. Value: " + k + "\n\n");

        short l = k.shortValue();
        System.out.print("Made a short int variable 'z' with y.shortValue() function.\n\n");

        System.out.print("The value of z = " + l + "\n\n");


        // Long
        System.out.print("\nEnter a long int: ");
        long m = input.nextLong();
        System.out.print("\nValue of taken long int: " +  m + "\n\n");

        Long n = m;
        System.out.print("Created Object 'y' of Wrapper Class 'Integer'. Value: " + n + "\n\n");

        long o = n.longValue();
        System.out.print("Made an int variable 'z' with y.longValue() function.\n\n");

        System.out.print("The value of z = " + o + "\n\n");

        // Byte
        System.out.print("\nEnter a byte-sized int: ");
        byte p = input.nextByte();
        System.out.printf("\nValue of taken integer: %d\n\n", p);

        Byte q = p;
        System.out.print("Created Object 'y' of Wrapper Class 'Integer'. Value: " + q + "\n\n");

        byte r = q.byteValue();
        System.out.print("Made an int variable 'z' with y.byteValue() function.\n\n");

        System.out.print("The value of z = " + r + "\n\n");


        // Boolean
        System.out.print("\nEnter a boolean value: ");
        boolean s = input.nextBoolean();
        System.out.printf("\nValue of taken boolean: %b\n\n", s);

        Boolean t = s;
        System.out.print("Created Object 'y' of Wrapper Class 'Integer'. Value: " + t + "\n\n");

        boolean u = t.booleanValue();
        System.out.print("Made an int variable 'z' with y.booleanValue() function.\n\n");

        System.out.print("The value of z = " + u + "\n\n");

        input.close();
    }
}
