package Assignment10;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int op = 0;
        CarFactory carFactory = new CarFactory();
        do {
            System.out.println( "\nEnter the type of car you want to build : \n1. Small car\n2. Sedan Car\n3. Luxury Car\n4. HetchBack car");
            System.out.print("Enter your choice : ");
            op = sc.nextInt();

            switch (op) {
                case 1:
                    Car obj = carFactory.buildCar(Cartype.SMALL);
                    obj.input();
                    obj.display(obj);
                    break;
                case 2:
                    Car obj1 = carFactory.buildCar(Cartype.SEDAN);
                    obj1.input();
                    obj1.display(obj1);
                    break;
                case 3:
                    Car obj2 = carFactory.buildCar(Cartype.LUXURY);
                    obj2.input();
                    obj2.display(obj2);
                    break;

                case 4:
                    Car obj3 = carFactory.buildCar(Cartype.HETCHBACK);
                    obj3.input();
                    obj3.display(obj3);
                    break;
                case 0:
                    System.out.println("\nProgram ends");
                    break;
                default:
                    System.out.println("Invalid input");
            }
        } while (op != 0);
    }
}
