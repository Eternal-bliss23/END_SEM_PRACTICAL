// Question 17: Evaluate Postfix Expression
// Purpose: Scan a space-separated postfix expression left-to-right with a stack.

import java.util.Scanner;
import java.util.Stack;

public class Q17_EvaluatePostfix {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter postfix (e.g. 3 2 4 * +): ");
        String line = sc.nextLine().trim();
        String[] tokens = line.split(" ");
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < tokens.length; i++) {        // left to right
            String t = tokens[i];
            if (isOperator(t)) {
                int b = st.pop();              // second operand
                int a = st.pop();              // first operand
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
        System.out.println("Postfix expression: " + line);
        System.out.println("Result: " + st.pop());
        sc.close();
    }

    static boolean isOperator(String s) {
        return s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/");
    }
}
