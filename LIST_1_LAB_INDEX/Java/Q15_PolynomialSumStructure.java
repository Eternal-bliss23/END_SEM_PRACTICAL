// Question 15: Sum of Two Polynomials Using a Structure
// Purpose: Keep degree and coefficients together in a class, then add them.
import java.util.Scanner;

public class Q15_PolynomialSumStructure {
    static class Poly {
        int deg;
        int[] coeff;   // coeff[i] is the coefficient of x^i
    }
    static Scanner sc = new Scanner(System.in);

    static Poly readPoly(String label) {
        Poly p = new Poly();
        System.out.print("Degree of " + label + ": ");
        p.deg = sc.nextInt();
        p.coeff = new int[p.deg + 1];
        for (int i = 0; i <= p.deg; i++) {
            System.out.print("Coefficient of x^" + i + ": ");
            p.coeff[i] = sc.nextInt();
        }
        return p;
    }

    static void printPoly(int[] c) {
        boolean first = true;
        for (int i = c.length - 1; i >= 0; i--) {
            if (c[i] == 0) continue;
            if (!first) System.out.print(" + ");
            if (i == 0) System.out.print(c[i]);
            else if (c[i] == 1) System.out.print("x^" + i);
            else System.out.print(c[i] + "x^" + i);
            first = false;
        }
        if (first) System.out.print("0");
        System.out.println();
    }

    public static void main(String[] args) {
        Poly a = readPoly("first polynomial");
        Poly b = readPoly("second polynomial");
        int max = Math.max(a.deg, b.deg);
        int[] sum = new int[max + 1];
        for (int i = 0; i <= max; i++) {
            int ca = (i <= a.deg) ? a.coeff[i] : 0;
            int cb = (i <= b.deg) ? b.coeff[i] : 0;
            sum[i] = ca + cb;
        }
        System.out.print("First polynomial : ");
        printPoly(a.coeff);
        System.out.print("Second polynomial: ");
        printPoly(b.coeff);
        System.out.print("Sum              : ");
        printPoly(sum);
        sc.close();
    }
}
