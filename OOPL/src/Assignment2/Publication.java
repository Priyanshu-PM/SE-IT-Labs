//  Name : Priyanshu Mahukhaye
//  Roll no : 23385
//  Assignment 2

package Assignment2;
import java.util.*;

public class Publication {
    public
    String author, title;
    Scanner sc = new Scanner(System.in);
    float price, copies;

    float salecopy() {
        System.out.println("The total sale of the publication is : "+price*copies);
        return price*copies;
    }
}

class Book extends Publication {
    public

    void getDetails() {
        System.out.print("Enter the name of the book : ");
        title = sc.nextLine();
        System.out.print("Enter the name of the author : ");
        author = sc.nextLine();
        System.out.print("Enter the price of the book : ");
        price = sc.nextInt();
        System.out.print("Enter the copies of the book : ");
        copies = sc.nextInt();
    }

    void displaySales() {
        System.out.println("The title of the book is : "+title);
        System.out.println("The author of the book is : "+author);
        System.out.println("The price of the book is : "+price);
        System.out.println("the total copies of the book are : "+copies);
        System.out.println("The total sales of the book is of Rs : "+salecopy());
    }

    float salecopy() {
        // System.out.println("Total sale of Book is : "+(price*copies));
        return price*copies;
    }
}

class Magazine extends Publication {
    public
    int currentIssue;

    void receiveIssue() {
        System.out.print("Enter the name of the magazine : ");
        title = sc.nextLine();
        System.out.print("Enter the name of the Publication : ");
        author = sc.nextLine();
        System.out.println("Enter the current issue no : ");
        currentIssue = sc.nextInt();
        System.out.print("Enter the price of the magazine : ");
        price = sc.nextInt();
        System.out.print("Enter the copies of the magazine : ");
        copies = sc.nextInt();
    }

    void displaySales() {
        System.out.println("The title of the magazine is : "+title);
        System.out.println("The author of the magazine is : "+author);
        System.out.println("The price of the magazine is : "+price);
        System.out.println("The current issue number is : "+currentIssue);
        System.out.println("the total copies of the magazine are : "+copies);
        System.out.println("The total sales of the magazine is of Rs : "+salecopy());
    }
    float salecopy() {
        return price*copies;
    }

}