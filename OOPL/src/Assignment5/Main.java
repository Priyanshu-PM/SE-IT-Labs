//  Name : Priyanshu Mahukhaye
//  Roll no : 23385
//  Assignment 5

package Assignment5;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int choice = 0;
        Vehicle v1;
        do {
            System.out.println("\nWelcome to the interface program\n");
            System.out.println("1. for bicycle\n2. for Car\n3. for Bike\n0. for exit");
            System.out.print("Which vehicle do you want to ride or drive : ");
            choice = sc.nextInt();
            switch(choice)
            {
                case 1:
                {
                    v1 = new Bicycle();
                    v1.gearChange(3);
                    System.out.println("Gear changed !!");
                    v1.getStatus();
                    v1.speedUp();
                    System.out.println("Speed has been increased !!");
                    v1.getStatus();
                    v1.applyBrake();
                    v1.getStatus();
                    break;
                }

                case 2:
                {
                    v1 = new Car();
                    v1.gearChange(3);
                    System.out.println("Gear changed !!");
                    v1.getStatus();
                    v1.speedUp();
                    System.out.println("Speed has been increased !!");
                    v1.getStatus();
                    v1.applyBrake();
                    v1.getStatus();
                    break;
                }

                case 3:
                {
                    v1 = new Bike();
                    v1.gearChange(3);
                    System.out.println("Gear changed !!");
                    v1.getStatus();
                    v1.speedUp();
                    System.out.println("Speed has been increased !!");
                    v1.getStatus();
                    v1.applyBrake();
                    v1.getStatus();
                    break;
                }

                case 0:
                {
                    System.out.println("Program terminated successfully !!");
                    System.exit(1);
                }

                default:
                {
                    System.out.println("Wrong choice entered !!");
                }
            }
        }while(choice != 0);
    }
}
