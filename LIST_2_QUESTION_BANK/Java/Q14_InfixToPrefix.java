// Question 14: Infix to Prefix
// Purpose: Reverse infix, swap brackets, get postfix, then reverse it to prefix.

import java.util.Scanner;
import java.util.Stack;

public class Q14_InfixToPrefix {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter infix (single letters, e.g. A+(B*C)): ");
        String infix = sc.next();

        // Step 1: reverse the expression and swap '(' with ')'
        String rev = "";
        for (int i = infix.length() - 1; i >= 0; i--) {
            char ch = infix.charAt(i);
            if (ch == '(') ch = ')';
            else if (ch == ')') ch = '(';
            rev += ch;
        }

        // Step 2: convert the reversed expression to postfix
        String postfix = toPostfix(rev);

        // Step 3: reverse the postfix tokens to get prefix
        String[] tokens = postfix.split(" ");
        String prefix = "";
        for (int i = tokens.length - 1; i >= 0; i--) {
            prefix += tokens[i] + " ";
        }
        System.out.println("Infix:   " + infix);
        System.out.println("Prefix:  " + prefix.trim());
        sc.close();
    }

    static int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    static String toPostfix(String s) {
        Stack<Character> st = new Stack<>();
        String out = "";
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (Character.isLetterOrDigit(ch)) {
                out += ch + " ";
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (!st.isEmpty() && st.peek() != '(') {
                    out += st.pop() + " ";
                }
                st.pop();                       // remove '('
            } else {                            // an operator
                while (!st.isEmpty() && st.peek() != '('
                       && precedence(st.peek()) > precedence(ch)) {
                    out += st.pop() + " ";
                }
                st.push(ch);
            }
        }
        while (!st.isEmpty()) out += st.pop() + " ";
        return out.trim();
    }
}
