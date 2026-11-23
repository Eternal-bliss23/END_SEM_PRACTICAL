import java.util.Scanner;

public class Q30_GraphDegreeMatrix {
    static void run(Scanner sc) {
        System.out.print("Number of vertices: ");
        int n = sc.nextInt();
        if (n <= 0) { System.out.println("Invalid vertex count"); return; }
        int[][] a = new int[n][n];
        System.out.println("Enter adjacency matrix (0/1):");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = sc.nextInt();
        System.out.print("Directed? (1 = yes, 0 = no): ");
        boolean directed = sc.nextInt() == 1;
        System.out.println("Vertex\tOut\tIn\tTotal");
        for (int i = 0; i < n; i++) {
            int out = 0, in = 0;
            for (int j = 0; j < n; j++) { out += a[i][j]; in += a[j][i]; }
            if (!directed) in = out;
            System.out.println(i + "\t" + out + "\t" + in + "\t" + (in + out));
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.println("1 Enter matrix and compute degrees  2 Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            if (ch == 1) run(sc);
            else if (ch != 2) System.out.println("Invalid choice");
        } while (ch != 2);
        sc.close();
    }
}
