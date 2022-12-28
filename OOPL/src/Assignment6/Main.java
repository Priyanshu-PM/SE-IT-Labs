//  Name : Priyanshu Mahukhaye
//  Roll no : 23385
//  Assignment 6

package Assignment6;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int arr[] = new int[5];
        try {
            System.out.print("Enter the first number : ");
            int a = sc.nextInt();
            System.out.print("Enter the second number : ");
            int b = sc.nextInt();
            int div = a/b;
            System.out.println("The division of the two numbers is : "+div);
            System.out.print("Enter the number to be converted into string : ");
            String num = sc.next();
            int n = Integer.parseInt(num);
            System.out.println("The number converted from the string is : "+n);

        }
        catch(InputMismatchException e) {
            System.out.println("Input mismatch exception occurred !!"+e.getMessage());
        }

        catch(NumberFormatException e) {
            System.out.println("Number format exception occured !! "+e.getMessage());
        }

        catch(ArithmeticException e) {
            System.out.println("Arithmetic exception occurred "+e.getMessage());
        }

        try {
            arr[6] = 65;
        }
        catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("Array index out of bounds exception occurred !! "+e.getMessage());
        }
    }
}
