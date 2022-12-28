//  Name : Priyanshu Mahukhaye
//  Roll no : 23385
//  Assignment 4

package Assignment4;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int choice = 0;
        Shape s1;
        do {
            System.out.println("\nWelcome to the dynamic binding program\n\n1. for rectangle\n2. for triangle\n0. for exit");
            System.out.print("Enter your choice : ");
            choice = sc.nextInt();
            switch(choice) {
                case 1:
                {
                    s1 = new Rectangle();
                    s1.computeArea();
                    break;
                }

                case 2:
                {
                    s1 = new Triangle();
                    s1.computeArea();
                    break;
                }
                case 0:
                {
                    System.out.println("Program terminated successfully !!");
                    System.exit(1);
                }
                default:
                {
                    System.out.println("Wrong choice entered !!");
                }
            }
        }while(choice != 0);

    }
}
