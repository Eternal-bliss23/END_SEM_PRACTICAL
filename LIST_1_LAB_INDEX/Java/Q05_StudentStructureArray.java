// Question 5: Array of Student Structures
// Purpose: Store student records in an array and print them as a table.
import java.util.Scanner;

public class Q05_StudentStructureArray {
    static class Student {
        int roll;
        String name;
        double marks;
    }
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        Student[] s = new Student[n];
        for (int i = 0; i < n; i++) {
            s[i] = new Student();
            System.out.print("Roll: ");
            s[i].roll = sc.nextInt();
            System.out.print("Name: ");
            s[i].name = sc.next();
            System.out.print("Marks: ");
            s[i].marks = sc.nextDouble();
        }
        System.out.println("Roll\tName\tMarks");
        for (int i = 0; i < n; i++)
            System.out.println(s[i].roll + "\t" + s[i].name + "\t" + s[i].marks);
        sc.close();
    }
}
