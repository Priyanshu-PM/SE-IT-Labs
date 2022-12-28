//  Name : Priyanshu Mahukhaye
//  Roll no : 23385
//  Assignment 11

package Assignment11;
import java.util.*;
public class Main {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int choice = 0;

        Cart cart = new Cart();
        Item a = new Item("Headphones", 2000);
        cart.addItem(new Item("Sneakers", 1000));
        cart.addItem(new Item("BoAt", 1500));
        cart.addItem(new Item("watch", 500));
        cart.addItem(a);
        System.out.println("\n\nYour total purchase is : ");
        cart.displayCart();
        System.out.println("\nHow do you want to pay :\n1. for credit card\n2. for Paypal\n3. for Bitcoin\n4. cancel purchase\n");
        System.out.print("Enter your choice : ");
        choice = sc.nextInt();
        
        switch(choice) {
            case 1: {
                cart.MakePayment(new CreditCard("PriyanshuMahukhaye", 234234, 12345678));
                break;
            }

            case 2: {
                cart.MakePayment(new PayPal("priyanshupm", 6464));
                break;
            }

            case 3: {
                cart.MakePayment(new Bitcoin("priyanshu8797", 20031516));
                break;
            }
            
            case 4: {

                System.out.println("Purchase cancel !! ");
                System.exit(1);
            }

            default: {
                System.out.println("Wrong choice entered !!");
                Main.main(new String[6]);
            }

        }
        sc.close();

    }
}
