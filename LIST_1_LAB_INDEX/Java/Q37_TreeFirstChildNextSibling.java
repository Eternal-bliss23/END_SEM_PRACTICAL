import java.util.Scanner;

public class Q37_TreeFirstChildNextSibling {
    static int[] firstChild, nextSibling;

    static void preorder(int u) {
        if (u < 0) return;
        System.out.print(u + " ");
        int c = firstChild[u];
        while (c != -1) { preorder(c); c = nextSibling[c]; }
    }
    static void run(Scanner sc) {
        System.out.print("Number of nodes: ");
        int n = sc.nextInt();
        if (n <= 0) { System.out.println("Invalid node count"); return; }
        firstChild = new int[n];
        nextSibling = new int[n];
        boolean[] hasParent = new boolean[n];
        for (int i = 0; i < n; i++) { firstChild[i] = -1; nextSibling[i] = -1; }
        System.out.println("Enter parent-child pairs (p c), 0-based, -1 -1 to stop:");
        while (true) {
            int p = sc.nextInt(), c = sc.nextInt();
            if (p == -1 && c == -1) break;
            if (p < 0 || p >= n || c < 0 || c >= n) { System.out.println("Invalid pair"); continue; }
            if (firstChild[p] == -1) firstChild[p] = c;
            else {
                int x = firstChild[p];
                while (nextSibling[x] != -1) x = nextSibling[x];
                nextSibling[x] = c;
            }
            hasParent[c] = true;
        }
        System.out.println("Node\tFirstChild\tNextSibling");
        for (int i = 0; i < n; i++)
            System.out.println(i + "\t" + firstChild[i] + "\t\t" + nextSibling[i]);
        int root = -1;
        for (int i = 0; i < n; i++) if (!hasParent[i]) { root = i; break; }
        System.out.print("Preorder: ");
        preorder(root);
        System.out.println();
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
