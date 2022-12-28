package Assignment11;

public class PayPal implements PaymentStrategy{
    private
    float balance = 20000;
    String userId;
    int pass;

    public

    PayPal(String username, int password) {
        userId = username;
        pass = password;

    }@Override
    public void pay(float amount) {
        if(amount < balance) {
            System.out.print("The money transferred from the paypal account is : "+amount+"\nRemaining balance is : "+(balance-amount));
            System.out.println("\nPayment done !!");
        }
        else {
            System.out.println("Not enough money !!");
        }
    }
    
}