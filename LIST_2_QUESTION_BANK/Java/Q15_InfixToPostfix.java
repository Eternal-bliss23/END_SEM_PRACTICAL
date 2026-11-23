// Question 15: Infix to Postfix
// Purpose: Convert an infix expression to postfix using an operator stack.

import java.util.Scanner;
import java.util.Stack;

public class Q15_InfixToPostfix {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter infix (single letters, e.g. A+(B*C)): ");
        String infix = sc.next();
        Stack<Character> st = new Stack<>();
        String postfix = "";

        for (int i = 0; i < infix.length(); i++) {
            char ch = infix.charAt(i);
            if (Character.isLetterOrDigit(ch)) {
                postfix += ch + " ";                // operand goes straight out
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (!st.isEmpty() && st.peek() != '(') {
                    postfix += st.pop() + " ";
                }
                st.pop();                           // discard '('
            } else {                                // an operator
                while (!st.isEmpty() && st.peek() != '('
                       && precedence(st.peek()) >= precedence(ch)) {
                    postfix += st.pop() + " ";
                }
                st.push(ch);
            }
        }
        while (!st.isEmpty()) postfix += st.pop() + " ";

        System.out.println("Infix:   " + infix);
        System.out.println("Postfix: " + postfix.trim());
        sc.close();
    }

    static int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }
}
