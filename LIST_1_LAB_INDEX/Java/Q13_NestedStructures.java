// Question 13: Nested Structures
// Purpose: Store a date inside a student record and print the nested members.
import java.util.Scanner;

public class Q13_NestedStructures {
    static class Date {
        int d, m, y;
    }
    static class Student {
        String name;
        Date dob;
    }
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        Student s = new Student();
        s.dob = new Date();
        System.out.print("Student name: ");
        s.name = sc.next();
        System.out.print("Day of birth: ");
        s.dob.d = sc.nextInt();
        System.out.print("Month of birth: ");
        s.dob.m = sc.nextInt();
        System.out.print("Year of birth: ");
        s.dob.y = sc.nextInt();

        System.out.println("Student name : " + s.name);
        System.out.println("Date of birth: " + s.dob.d + "/" + s.dob.m + "/" + s.dob.y);
        sc.close();
    }
}
