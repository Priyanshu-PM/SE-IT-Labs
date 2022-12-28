package Assignment10;

public class HetchBackCar extends Car{

    String features_avail;

    @Override
    void getPrice(double price) {
        if(price>5) features_avail = "YES";
        else features_avail = "NO";
    }

    @Override
    void detail(String comp, String car_n) {
        System.out.println("Company: "+comp);
        System.out.println("Car name: "+car_n);
        System.out.println("Colors: Black, White, Navy Blue, Gold, Yellow");
        System.out.println("Gear: Manual");
    }

    @Override
    void accessories() {
        System.out.println("Types of Tyres- CEAT, MRF");
        System.out.println("Airbags- "+features_avail);
        System.out.println("Back Wiper- "+features_avail);
        System.out.println("Touch Screen Music Player- "+features_avail);
    }
}