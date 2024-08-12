public class Section4 {
    public static void main(String[] args) {
        System.out.println("Hello World");

        // if-else statement
        boolean isAlien = false;
        if (isAlien == false) {
            System.out.println("It's not an Alien");
        } else {
            System.out.println("It's an Alien");
        }

        // Logical And Operator
        int topScore = 80;
        int secondTopScore = 60;
        if ((topScore > secondTopScore) && (topScore < 100)) {
            System.out.println("Top score is greater than second top score");
        }

        // Logical Or Operator
        if ((topScore > secondTopScore) || (topScore < 100)) {
            System.out.println("Top score is greater than second top score");
        }

        // Section 4 Challange
        double var1 = 20.0;
        double var2 = 80.0;

        double var3 = (var1 + var2) * 100.0;

        boolean isTrue = false;
        if ((var3 % 40) == 0) {
            isTrue = true;
        }
        else {
            System.out.println("Got some reaminder");
        }
    }
}