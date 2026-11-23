// Question 13: Reverse a String using Stack
// Purpose: Push each character on a stack, then pop to print the reversed string.

import java.util.Scanner;

public class Q13_ReverseStringStack {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter a word or string (no spaces): ");
        String s = sc.next();
        char[] stack = new char[s.length()];
        int top = -1;

        for (int i = 0; i < s.length(); i++) {
            stack[++top] = s.charAt(i);        // push each character
        }

        System.out.println("Original string: " + s);
        System.out.print("Reversed string: ");
        while (top >= 0) {
            System.out.print(stack[top--]);    // pop: last character comes first
        }
        System.out.println();
        sc.close();
    }
}
