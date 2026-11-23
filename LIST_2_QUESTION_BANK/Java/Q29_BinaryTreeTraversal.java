// Question 29: Binary Tree Traversals
// Purpose: Build a tree by level-order insertion and print three traversals.

import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class Q29_BinaryTreeTraversal {
    static class Node {
        int data;
        Node left, right;
        Node(int data) { this.data = data; }
    }
    static Scanner sc = new Scanner(System.in);
    static Node root = null;

    public static void main(String[] args) {
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        System.out.println("Enter " + n + " values:");
        for (int i = 0; i < n; i++) {
            System.out.print("Value " + (i + 1) + ": ");
            insert(sc.nextInt());
        }

        int choice;
        do {
            System.out.println("1. Preorder  2. Inorder  3. Postorder  0. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Preorder:  "); preorder(root); System.out.println(); break;
                case 2:
                    System.out.print("Inorder:   "); inorder(root); System.out.println(); break;
                case 3:
                    System.out.print("Postorder: "); postorder(root); System.out.println(); break;
                case 0: System.out.println("Exiting..."); break;
                default: System.out.println("Wrong choice!");
            }
        } while (choice != 0);
        sc.close();
    }

    // Insert at the first empty child found using level order (a Queue)
    static void insert(int value) {
        Node newNode = new Node(value);
        if (root == null) { root = newNode; return; }
        Queue<Node> q = new ArrayDeque<>();
        q.add(root);
        while (!q.isEmpty()) {
            Node cur = q.poll();
            if (cur.left == null) { cur.left = newNode; return; }
            else q.add(cur.left);
            if (cur.right == null) { cur.right = newNode; return; }
            else q.add(cur.right);
        }
    }

    static void preorder(Node n) {
        if (n == null) return;
        System.out.print(n.data + " ");
        preorder(n.left);
        preorder(n.right);
    }

    static void inorder(Node n) {
        if (n == null) return;
        inorder(n.left);
        System.out.print(n.data + " ");
        inorder(n.right);
    }

    static void postorder(Node n) {
        if (n == null) return;
        postorder(n.left);
        postorder(n.right);
        System.out.print(n.data + " ");
    }
}
