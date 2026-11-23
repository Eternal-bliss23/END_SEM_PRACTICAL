import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

public class Q33_GraphBFS {
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
            if (u >= 0 && u < n && v >= 0 && v < n) a[u][v] = a[v][u] = 1;
            else System.out.println("Invalid edge");
        }
        System.out.print("Start vertex: ");
        int s = sc.nextInt();
        if (s < 0 || s >= n) { System.out.println("Invalid start"); return; }
        boolean[] vis = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        vis[s] = true;
        System.out.print("BFS: ");
        while (!q.isEmpty()) {
            int u = q.poll();
            System.out.print(u + " ");
            for (int v = 0; v < n; v++)
                if (a[u][v] == 1 && !vis[v]) { vis[v] = true; q.add(v); }
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.println("1 Build graph and run BFS  2 Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            if (ch == 1) run(sc);
            else if (ch != 2) System.out.println("Invalid choice");
        } while (ch != 2);
        sc.close();
    }
}
