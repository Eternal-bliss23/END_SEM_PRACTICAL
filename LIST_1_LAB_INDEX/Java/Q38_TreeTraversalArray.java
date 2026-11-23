import java.util.Scanner;

public class Q38_TreeTraversalArray {
    static int[] data, left, right;

    static void preorder(int u) {
        if (u == -1) return;
        System.out.print(data[u] + " ");
        preorder(left[u]);
        preorder(right[u]);
    }
    static void inorder(int u) {
        if (u == -1) return;
        inorder(left[u]);
        System.out.print(data[u] + " ");
        inorder(right[u]);
    }
    static void postorder(int u) {
        if (u == -1) return;
        postorder(left[u]);
        postorder(right[u]);
        System.out.print(data[u] + " ");
    }
    static void run(Scanner sc) {
        System.out.print("Number of nodes: ");
        int n = sc.nextInt();
        if (n <= 0) { System.out.println("Invalid node count"); return; }
        data = new int[n];
        left = new int[n];
        right = new int[n];
        for (int i = 0; i < n; i++) { left[i] = -1; right[i] = -1; }
        System.out.println("For each node enter: index data leftIndex rightIndex (-1 = none)");
        for (int k = 0; k < n; k++) {
            System.out.print("Node " + k + ": ");
            int idx = sc.nextInt(), d = sc.nextInt(), l = sc.nextInt(), r = sc.nextInt();
            if (idx >= 0 && idx < n) { data[idx] = d; left[idx] = l; right[idx] = r; }
            else System.out.println("Invalid index");
        }
        System.out.print("Root index: ");
        int root = sc.nextInt();
        if (root < 0 || root >= n) { System.out.println("Invalid root"); return; }
        System.out.print("Preorder: "); preorder(root); System.out.println();
        System.out.print("Inorder: "); inorder(root); System.out.println();
        System.out.print("Postorder: "); postorder(root); System.out.println();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.println("1 Build tree and traverse  2 Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            if (ch == 1) run(sc);
            else if (ch != 2) System.out.println("Invalid choice");
        } while (ch != 2);
        sc.close();
    }
}
