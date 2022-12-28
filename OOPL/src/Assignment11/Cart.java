package Assignment11;
import java.util.*;

public class Cart {
    private
    
    List<Item> list;

    public
    Cart() {
        list = new ArrayList<Item>();
    }

    void addItem(Item i) {
        list.add(i);
    }

    void removeItem(Item i) {
        list.remove(i);
    }

    float calculateTotal() {
        float amount = 0;
        for (Item item : list) {
            amount += item.getPrice();
            
        }
        return amount;
    }

    void displayCart() {
        for (Item item : list) {
            System.out.println("Product name : "+item.getName()+"   Price : "+item.getPrice());
        }
        System.out.println();
    }

    void MakePayment(PaymentStrategy mode) {
        float amount = calculateTotal();
        mode.pay(amount);
        
    }
}
