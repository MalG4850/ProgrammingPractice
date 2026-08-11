import java.util.Scanner;

public class gradeDescription {

    static String gradeDesc(String grade) {
        String out = new String("");
        switch (grade) {
            case "A":
                out = "A => Excellent!";
                break;
            case "B":
                out = "B => Well done!";
                break;
            case "C":
                out = "C => Passed.";
                break;
            case "D":
                out = "D => More effort needed.";
                break;
        }
        return out;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("\nWhat is the grade of the student? ");
        String grade = input.next();
        String out = gradeDesc(grade);
        System.out.printf("\nFor this grade: \n\n%s\n\n", out);

        input.close();
    }
}
