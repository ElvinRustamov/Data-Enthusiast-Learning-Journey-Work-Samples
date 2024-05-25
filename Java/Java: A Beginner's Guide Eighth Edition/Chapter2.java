public class Chapter2 {
    public static void main(String[] args) {

        /*
        Compute the number of cubic inches in 1 cubic mile
        */
        long ci;
        long im;

        im = 5280 * 12;
        ci = im * im * im;

        System.out.println("There are " + ci + " cubic inches in cubic mile");

        /*
        Find the length of the hypotenuse
        */
        double x, y, z;

        x = 3;
        y = 4;

        z = Math.sqrt(x*x + y*y);
        System.out.println("Hypotenuse is " + z);

        /*
        Character variables can be handled like integers
        */
        char ch;
        ch = 'X';
        System.out.println("ch contains: " + ch);

        ch++;
        System.out.println("ch contains: " + ch);

        ch = 67;
        System.out.println("ch contains: " + ch);

        // How Far Away Is the Lightning ?
        float time_interval = 7.2F;
        int sound_travel = 1100;

        double distance = time_interval * sound_travel;
        System.out.println("The lightninh is " + distance + " feet away");

        // Demonstrate escape sequences in strings
        System.out.println("First line\nSecond Line");
        System.out.println("A\tB\tC");
    }
}
