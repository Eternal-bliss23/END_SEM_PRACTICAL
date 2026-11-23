import java.util.Scanner;
import java.util.ArrayList;

public class Q36_TreeAdjacencyList {
    static void run(Scanner sc) {
        System.out.print("Number of nodes: ");
        int n = sc.nextInt();
        if (n <= 0) { System.out.println("Invalid node count"); return; }
        ArrayList<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        System.out.println("Enter " + (n - 1) + " parent-child edges (p c), 0-based:");
        for (int k = 0; k < n - 1; k++) {
            int p = sc.nextInt(), c = sc.nextInt();
            if (p >= 0 && p < n && c >= 0 && c < n) adj[p].add(c);
            else System.out.println("Invalid edge");
        }
        System.out.println("Adjacency list:");
        for (int i = 0; i < n; i++) {
            System.out.print(i + " -> ");
            for (int v : adj[i]) System.out.print(v + " ");
            System.out.println();
        }
        System.out.println("Children of each node:");
        for (int i = 0; i < n; i++) {
            System.out.print("Node " + i + ": ");
            for (int v : adj[i]) System.out.print(v + " ");
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.println("1 Build and print tree list  2 Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            if (ch == 1) run(sc);
            else if (ch != 2) System.out.println("Invalid choice");
        } while (ch != 2);
        sc.close();
    }
}
