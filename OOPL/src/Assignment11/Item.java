package Assignment11;

public class Item {
    private
    String itemname;
    float cost;
    public
    Item(String name, float price) {
        itemname = name;
        cost = price;

    }

    String getName() {
         return itemname;
    }
    float getPrice() {
        return cost;
    }
}
