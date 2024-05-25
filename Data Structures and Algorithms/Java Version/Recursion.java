// Solving factorial with using recursion

// factorial(n) = n × factorial(n – 1)

public class Recursion {

    static int factorial(int n) {
        if (n == 1) return 1;
        else return n * factorial(n - 1);
    }

    public static void main(String[] args) {
        int n = 6;
        int answer = factorial(n);
        System.out.println(n + " factorial is " + answer);
    }
}
