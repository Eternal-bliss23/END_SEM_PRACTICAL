import java.util.Scanner;
import java.util.ArrayList;

public class Q32_GraphAdjacencyList {
    static void run(Scanner sc) {
        System.out.print("Number of vertices: ");
        int n = sc.nextInt();
        if (n <= 0) { System.out.println("Invalid vertex count"); return; }
        System.out.print("Number of edges: ");
        int e = sc.nextInt();
        ArrayList<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        System.out.println("Enter edges (u v), 0-based:");
        for (int k = 0; k < e; k++) {
            int u = sc.nextInt(), v = sc.nextInt();
            if (u >= 0 && u < n && v >= 0 && v < n) adj[u].add(v);
            else System.out.println("Invalid edge");
        }
        System.out.println("Adjacency list:");
        for (int i = 0; i < n; i++) {
            System.out.print(i + " -> ");
            for (int v : adj[i]) System.out.print(v + " ");
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.println("1 Build and print adjacency list  2 Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            if (ch == 1) run(sc);
            else if (ch != 2) System.out.println("Invalid choice");
        } while (ch != 2);
        sc.close();
    }
}
