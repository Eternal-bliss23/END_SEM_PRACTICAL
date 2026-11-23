// Question 11: Stack using Array
// Purpose: Implement push, pop, peek and display on a fixed-size array stack.

import java.util.Scanner;

public class Q11_StackArray {
    static Scanner sc = new Scanner(System.in);
    static final int MAX = 5;
    static int[] stack = new int[MAX];
    static int top = -1;

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("1. Push  2. Pop  3. Peek  4. Display  0. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    if (top == MAX - 1) {
                        System.out.println("Stack is full!");
                    } else {
                        System.out.print("Enter value to push: ");
                        stack[++top] = sc.nextInt();
                        System.out.println("Pushed successfully.");
                    }
                    break;
                case 2:
                    if (top == -1) System.out.println("Stack is empty!");
                    else System.out.println("Popped value: " + stack[top--]);
                    break;
                case 3:
                    if (top == -1) System.out.println("Stack is empty!");
                    else System.out.println("Top element: " + stack[top]);
                    break;
                case 4:
                    if (top == -1) System.out.println("Stack is empty!");
                    else {
                        System.out.print("Stack (top to bottom): ");
                        for (int i = top; i >= 0; i--) {
                            System.out.print(stack[i] + " ");
                        }
                        System.out.println();
                    }
                    break;
                case 0:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Wrong choice!");
            }
        } while (choice != 0);
        sc.close();
    }
}
