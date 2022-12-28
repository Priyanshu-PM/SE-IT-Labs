package Assignment8;
import java.util.*;

public class Main {
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        FileHandling f1 = new FileHandling();
        int choice = 0;
        do {
            
            System.out.println("\nWelcome to the student management student\n");
            System.out.println("1. adding students to the database\n2. displaying students of the database\n3. deleting the record\n0. exit");
            System.out.print("Enter your choice : ");
            choice = sc.nextInt();
            
            switch(choice) {

                case 1: {
                    f1.addRecord();
                    break;
                }

                case 2: {
                    f1.displayRecord();
                    break;
                    
                }
                case 3: {
                    f1.deleteRecord();
                    break;
                }
                case 0: {
                    System.out.println("Program terminated successfully !!\n");
                    System.exit(1);
                }

                default: {
                    System.out.println("Wrong choice entered !!\n");
                }
            }
        }
        while(choice != 0);
        sc.close();
    }
}
