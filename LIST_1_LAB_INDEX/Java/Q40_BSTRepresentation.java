import java.util.Scanner;

public class Q40_BSTRepresentation {
    static class Node {
        int key;
        Node left, right;
        Node(int k) { key = k; }
    }
    static Node root;

    static Node insert(Node u, int k) {
        if (u == null) return new Node(k);
        if (k < u.key) u.left = insert(u.left, k);
        else if (k > u.key) u.right = insert(u.right, k);
        return u;
    }
    static boolean search(Node u, int k) {
        if (u == null) return false;
        if (k == u.key) return true;
        return k < u.key ? search(u.left, k) : search(u.right, k);
    }
    static Node minNode(Node u) {
        while (u.left != null) u = u.left;
        return u;
    }
    static Node delete(Node u, int k) {
        if (u == null) return null;
        if (k < u.key) u.left = delete(u.left, k);
        else if (k > u.key) u.right = delete(u.right, k);
        else {
            if (u.left == null) return u.right;
            if (u.right == null) return u.left;
            Node m = minNode(u.right);
            u.key = m.key;
            u.right = delete(u.right, m.key);
        }
        return u;
    }
    static void inorder(Node u) {
        if (u == null) return;
        inorder(u.left);
        System.out.print(u.key + " ");
        inorder(u.right);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.println("1 Insert  2 Search  3 Inorder  4 Delete  5 Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            switch (ch) {
                case 1: System.out.print("Key: "); root = insert(root, sc.nextInt()); break;
                case 2: System.out.print("Key: ");
                        int k2 = sc.nextInt();
                        System.out.println(search(root, k2) ? "Found" : "Not found"); break;
                case 3: System.out.print("Inorder: "); inorder(root); System.out.println(); break;
                case 4: System.out.print("Key: "); root = delete(root, sc.nextInt()); break;
                case 5: break;
                default: System.out.println("Invalid choice");
            }
        } while (ch != 5);
        sc.close();
    }
}
