package Assignment11;
// import java.util.*;

public class CreditCard implements PaymentStrategy {
    private
    float balance = 30000;
    String userId;
    int cvnum;
    int pass;
    
    public

    CreditCard(String name, int cv, int password) {
        userId = name;
        cv = cvnum;
        pass = password;
    }
    @Override
    public void pay(float amount) {
        if(amount < balance) {
            System.out.println("The amount debited from the account is : "+amount+"\nThe remaining balance is : "+(balance-amount));
            System.out.println("\nPayment done !!");
        }
        else {
            System.out.println("Not enough money !!");
        }
    }
}
