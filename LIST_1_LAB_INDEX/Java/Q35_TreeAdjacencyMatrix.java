import java.util.Scanner;

public class Q35_TreeAdjacencyMatrix {
    static void run(Scanner sc) {
        System.out.print("Number of nodes: ");
        int n = sc.nextInt();
        if (n <= 0) { System.out.println("Invalid node count"); return; }
        int[][] a = new int[n][n];
        int[] parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = -1;
        System.out.println("Enter " + (n - 1) + " parent-child edges (p c), 0-based:");
        for (int k = 0; k < n - 1; k++) {
            int p = sc.nextInt(), c = sc.nextInt();
            if (p >= 0 && p < n && c >= 0 && c < n) { a[p][c] = 1; parent[c] = p; }
            else System.out.println("Invalid edge");
        }
        System.out.println("Adjacency matrix:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) System.out.print(a[i][j] + " ");
            System.out.println();
        }
        System.out.print("Parent array: ");
        for (int i = 0; i < n; i++) System.out.print(parent[i] + " ");
        System.out.println();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.println("1 Build and print tree matrix  2 Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            if (ch == 1) run(sc);
            else if (ch != 2) System.out.println("Invalid choice");
        } while (ch != 2);
        sc.close();
    }
}
