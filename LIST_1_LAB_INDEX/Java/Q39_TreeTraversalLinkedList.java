import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

public class Q39_TreeTraversalLinkedList {
    static class Node {
        int data;
        Node left, right;
        Node(int d) { data = d; }
    }
    static Node root;

    static void insert(int v) {
        Node n = new Node(v);
        if (root == null) { root = n; return; }
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            Node cur = q.poll();
            if (cur.left == null) { cur.left = n; return; }
            if (cur.right == null) { cur.right = n; return; }
            q.add(cur.left);
            q.add(cur.right);
        }
    }
    static void preorder(Node u) {
        if (u == null) return;
        System.out.print(u.data + " ");
        preorder(u.left);
        preorder(u.right);
    }
    static void inorder(Node u) {
        if (u == null) return;
        inorder(u.left);
        System.out.print(u.data + " ");
        inorder(u.right);
    }
    static void postorder(Node u) {
        if (u == null) return;
        postorder(u.left);
        postorder(u.right);
        System.out.print(u.data + " ");
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.println("1 Insert  2 Preorder  3 Inorder  4 Postorder  5 Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            switch (ch) {
                case 1: System.out.print("Data: "); insert(sc.nextInt()); break;
                case 2: System.out.print("Preorder: "); preorder(root); System.out.println(); break;
                case 3: System.out.print("Inorder: "); inorder(root); System.out.println(); break;
                case 4: System.out.print("Postorder: "); postorder(root); System.out.println(); break;
                case 5: break;
                default: System.out.println("Invalid choice");
            }
        } while (ch != 5);
        sc.close();
    }
}
