public class Section5 {
    public static void main(String[] args) {

        // if then else challenge
        int score = 10000;
        int levelCompleted = 8;
        int bonus = 200;
        boolean gameOver = true;

        int finalScore = score;

        if (gameOver) {
            finalScore += (levelCompleted * bonus);
            System.out.println("Your final score was " + finalScore);
        }
        calculate();
        int calculate_second_version = calculate_version_two(5, 7);
        System.out.println("Function name: 'calculate_second_version': " + calculate_second_version);

        //Overloaded Method Challenge
        double myHeightInch = convertToCentimeters(175);
        System.out.println("HeightInch: " + myHeightInch);

        double new_height = convertToCentimeters(5, 8);
        System.out.println("New height: " + new_height);

    }

    public static void calculate() {
        int a = 10;
        int b = 20;
        System.out.println(a + b);
    }

    public static int calculate_version_two(int a, int b) {
       return a + b;
    }

    public static double convertToCentimeters(int height) {
        return height * 2.54;
    }

    public static double convertToCentimeters(int height, int height_inch) {
        int new_height = (height * 12) + height_inch;
        return convertToCentimeters(new_height);
    }
}
