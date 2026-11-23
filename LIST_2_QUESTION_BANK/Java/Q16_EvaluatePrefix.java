// Question 16: Evaluate Prefix Expression
// Purpose: Scan a space-separated prefix expression right-to-left with a stack.

import java.util.Scanner;
import java.util.Stack;

public class Q16_EvaluatePrefix {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter prefix (e.g. + 3 * 2 4): ");
        String line = sc.nextLine().trim();
        String[] tokens = line.split(" ");
        Stack<Integer> st = new Stack<>();

        for (int i = tokens.length - 1; i >= 0; i--) {   // right to left
            String t = tokens[i];
            if (isOperator(t)) {
                int a = st.pop();              // first operand
                int b = st.pop();              // second operand
                switch (t) {
                    case "+": st.push(a + b); break;
                    case "-": st.push(a - b); break;
                    case "*": st.push(a * b); break;
                    case "/": st.push(a / b); break;
                }
            } else {
                st.push(Integer.parseInt(t));
            }
        }
        System.out.println("Prefix expression: " + line);
        System.out.println("Result: " + st.pop());
        sc.close();
    }

    static boolean isOperator(String s) {
        return s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/");
    }
}
