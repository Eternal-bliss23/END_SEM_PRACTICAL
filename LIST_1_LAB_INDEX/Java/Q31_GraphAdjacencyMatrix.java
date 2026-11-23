import java.util.Scanner;

public class Q31_GraphAdjacencyMatrix {
    static void run(Scanner sc) {
        System.out.print("Number of vertices: ");
        int n = sc.nextInt();
        if (n <= 0) { System.out.println("Invalid vertex count"); return; }
        System.out.print("Number of edges: ");
        int e = sc.nextInt();
        int[][] a = new int[n][n];
        System.out.println("Enter edges (u v), 0-based:");
        for (int k = 0; k < e; k++) {
            int u = sc.nextInt(), v = sc.nextInt();
            if (u >= 0 && u < n && v >= 0 && v < n) a[u][v] = 1;
            else System.out.println("Invalid edge");
        }
        System.out.print("   ");
        for (int i = 0; i < n; i++) System.out.print(i + " ");
        System.out.println();
        for (int i = 0; i < n; i++) {
            System.out.print(i + ": ");
            for (int j = 0; j < n; j++) System.out.print(a[i][j] + " ");
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.println("1 Build and print matrix  2 Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            if (ch == 1) run(sc);
            else if (ch != 2) System.out.println("Invalid choice");
        } while (ch != 2);
        sc.close();
    }
}
