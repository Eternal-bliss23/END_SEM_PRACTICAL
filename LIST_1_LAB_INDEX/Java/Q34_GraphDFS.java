import java.util.Scanner;

public class Q34_GraphDFS {
    static int[][] a;
    static boolean[] vis;
    static void dfs(int u) {
        vis[u] = true;
        System.out.print(u + " ");
        for (int v = 0; v < a.length; v++)
            if (a[u][v] == 1 && !vis[v]) dfs(v);
    }
    static void run(Scanner sc) {
        System.out.print("Number of vertices: ");
        int n = sc.nextInt();
        if (n <= 0) { System.out.println("Invalid vertex count"); return; }
        System.out.print("Number of edges: ");
        int e = sc.nextInt();
        a = new int[n][n];
        System.out.println("Enter edges (u v), 0-based:");
        for (int k = 0; k < e; k++) {
            int u = sc.nextInt(), v = sc.nextInt();
            if (u >= 0 && u < n && v >= 0 && v < n) a[u][v] = a[v][u] = 1;
            else System.out.println("Invalid edge");
        }
        System.out.print("Start vertex: ");
        int s = sc.nextInt();
        if (s < 0 || s >= n) { System.out.println("Invalid start"); return; }
        vis = new boolean[n];
        System.out.print("DFS: ");
        dfs(s);
        System.out.println();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.println("1 Build graph and run DFS  2 Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            if (ch == 1) run(sc);
            else if (ch != 2) System.out.println("Invalid choice");
        } while (ch != 2);
        sc.close();
    }
}
