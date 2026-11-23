// Question 12: Self-Referential Structure
// Purpose: Link three nodes together and walk the chain to print their data.
import java.util.Scanner;

public class Q12_SelfReferentialStructure {
    static class Node {
        int data;
        Node next;
        Node(int d) { data = d; }
    }
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Data for node 1: ");
        Node first = new Node(sc.nextInt());
        System.out.print("Data for node 2: ");
        Node second = new Node(sc.nextInt());
        System.out.print("Data for node 3: ");
        Node third = new Node(sc.nextInt());

        first.next = second;
        second.next = third;
        // third.next stays null, so the chain ends there
        System.out.println("Linked list data:");
        Node current = first;
        while (current != null) {
            System.out.println("data = " + current.data);
            current = current.next;
        }
        sc.close();
    }
}
