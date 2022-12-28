package Assignment11;
// import java.util.*;

public class Bitcoin implements PaymentStrategy{
    private
    float bitcoin = 5;
    String cryptoId;
    int password;

    public

    Bitcoin(String cryId, int pass) {
        cryptoId = cryId;
        password = pass;

    }
    @Override
    public void pay(float amount) {
        if(amount/30000 < bitcoin) {
            float rem = bitcoin - (amount/30000);
            System.out.println("The bitcoin transferred from the account is : "+amount/30000+"\nRemaining bitcoin are : "+rem);
            System.out.println("\nPayment done !!");
        }
        else {
            System.out.println("Not enough bitcoins in the account !!");
        }
    }

}
