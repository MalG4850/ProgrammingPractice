public class Test {
    public static void main(String[] args) {
        printAlpha a = new printAlpha();
        printNums t1 = new printNums();
        Thread t2 = new Thread(a);

        t1.run();
        t2.run();
    }
}
