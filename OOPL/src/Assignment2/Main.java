//  Name : Priyanshu Mahukhaye
//  Roll no : 23385
//  Assingment 2

package Assignment2;
import java.util.*;

public class Main {
    //    Driver code
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Book b1 = new Book();
        Magazine m1 = new Magazine();
        System.out.println("Welcome to the Polymorphism program\n");
        System.out.println("Enter the book details : ");
        b1.getDetails();
        System.out.println("Enter the magazine details : ");
        m1.receiveIssue();
        System.out.println("\nThe total sales of the books is : "+b1.salecopy());
        System.out.println("The total sale of the magazine is : "+m1.salecopy());
        System.out.println("\nThe total sales of the publication is : "+(b1.salecopy()+m1.salecopy()));
    }
}
