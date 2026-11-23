import java.util.Scanner;
import java.util.Stack;

public class Q25_InfixToPrefix {
    static int prec(char c) {
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
        if (c == '^') return 3;
        return 0;
    }
    static String toPostfix(String s) {
        Stack<Character> st = new Stack<>();
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c) || Character.isLetter(c)) out.append(c);
            else if (c == '(') st.push(c);
            else if (c == ')') {
                while (!st.isEmpty() && st.peek() != '(') out.append(st.pop());
                st.pop();
            } else {
                while (!st.isEmpty() && st.peek() != '(' &&
                       (prec(st.peek()) > prec(c) || (prec(st.peek()) == prec(c) && c != '^')))
                    out.append(st.pop());
                st.push(c);
            }
        }
        while (!st.isEmpty()) out.append(st.pop());
        return out.toString();
    }
    static String toPrefix(String s) {
        StringBuilder rev = new StringBuilder(s).reverse();
        for (int i = 0; i < rev.length(); i++) {
            char c = rev.charAt(i);
            if (c == '(') rev.setCharAt(i, ')');
            else if (c == ')') rev.setCharAt(i, '(');
        }
        return new StringBuilder(toPostfix(rev.toString())).reverse().toString();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.print("Enter infix (no spaces): ");
            String s = sc.next();
            System.out.println("Prefix: " + toPrefix(s));
            System.out.print("Again? (1 = yes): ");
            ch = sc.nextInt();
        } while (ch == 1);
        sc.close();
    }
}
