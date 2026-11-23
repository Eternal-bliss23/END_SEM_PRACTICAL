// Question 16: Sum of Two Polynomials Using an Array of Structures
// Purpose: Store each term as (coefficient, exponent) and combine like terms.
import java.util.Scanner;

public class Q16_PolynomialSumArrayOfStructures {
    static class Term {
        int coeff, exp;
    }
    static Scanner sc = new Scanner(System.in);

    static Term[] readPoly(String label) {
        System.out.print("Number of terms in " + label + ": ");
        int t = sc.nextInt();
        Term[] p = new Term[t];
        for (int i = 0; i < t; i++) {
            p[i] = new Term();
            System.out.print("Term " + (i + 1) + " - coefficient: ");
            p[i].coeff = sc.nextInt();
            System.out.print("               exponent: ");
            p[i].exp = sc.nextInt();
        }
        return p;
    }

    static void printPoly(Term[] p) {
        System.out.println("Coefficient\tExponent");
        for (int i = 0; i < p.length; i++)
            if (p[i].coeff != 0)
                System.out.println(p[i].coeff + "\t\t" + p[i].exp);
    }

    public static void main(String[] args) {
        Term[] a = readPoly("first polynomial");
        Term[] b = readPoly("second polynomial");
        Term[] sum = new Term[a.length + b.length];
        int k = 0;
        for (int i = 0; i < a.length; i++) sum[k++] = a[i];
        for (int i = 0; i < b.length; i++) sum[k++] = b[i];

        for (int i = 0; i < k; i++)
            for (int j = i + 1; j < k; j++)
                if (sum[i].exp == sum[j].exp) {
                    sum[i].coeff += sum[j].coeff;
                    sum[j].coeff = 0;   // mark this term as already merged
                }
        System.out.println("Sum polynomial terms:");
        printPoly(sum);
        sc.close();
    }
}
