import java.util.*;


public class euclidean_gcd {

    /*
    * Calculates GCD of two numbers a & b using the division-based
    * Euclidean Algorithm
    */
    public static long euclideanGcdDivision(long x, long y) {
        while(y != 0) {
            long temp =y;
            y=x%y;
            x=temp;
        }
        return x;
    }

    /*
    * Calculates GCD of two numbers a & b using the Recursive-based
    * Euclidean Algorithm
    */
    public static long euclideanGcdRecursive(long x, long y) {
        if (x == 0)
            return y;
        return euclideanGcdRecursive(y%x, x);
    }

    /*
    * Calculates GCD of two numbers a & b using the Recursive-based Extended
    * Euclidean Algorithm
    */
    public void extendedGcd(long a, long b) {
        long gcd_rec = euclideanGcdRecursive(a,b);
        System.out.println("Extended_Recursive: GCD of " +a+ " & " +b+ " is : " +gcd_rec);
        long x = 0, y = 1, Prev_x = 1, Prev_y = 0, temp;
        while (b != 0) {
            long q = a / b;
            long r = a % b;
            a = b;
            b = r;
            temp = x;
            x = Prev_x - q * x;
            Prev_x = temp;
            temp = y;
            y = Prev_y - q * y;
            Prev_y = temp;
        }
        System.out.println("Roots  x : "+ Prev_x +" y :"+ Prev_y);
    }

    public static void main (String[] args) {
        long a = 20;
        long b = 30;

        long gcd_div = euclideanGcdDivision(a, b);
        System.out.println("Division: GCD of " +a+ " & " +b+ " is : " + gcd_div);

        long gcd_rec = euclideanGcdRecursive(a, b);
        System.out.println("Recursive: GCD of " +a+ " & " +b+ " is : " + gcd_rec);

        euclidean_gcd obj = new euclidean_gcd();
        obj.extendedGcd(a, b);
    }
}
