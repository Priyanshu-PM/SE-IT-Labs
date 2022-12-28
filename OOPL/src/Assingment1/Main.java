package Assingment1;
import java.util.*;
public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Welcome to the complex number program\n========================================");
        Complex c1 = Complex.createComplex();
        Complex c2 = Complex.createComplex();

        int choice = 0;
        do {

            System.out.println("1. for addition\n2. for subtraction\n3. for multiplication\n4. for division\n5. Create new complex numbers\n");
            System.out.print("Enter your choice :");
            choice = sc.nextInt();

            switch(choice) {
                case 1: {
                    System.out.println("Addition is : "+Complex.addComplex(c1, c2));
                    break;
                }
                case 2: {
                    System.out.println("Subtraction is : "+Complex.subComplex(c1, c2));
                    break;
                }
                case 3: {
                    System.out.println("Multiplication is : "+ Complex.mulComplex(c1, c2));
                    break;
                }
                case 4: {
                    System.out.println("Division is : "+Complex.divComplex(c1, c2));
                    break;
                }
                case 5: {
                    main(new String[2]);
                }
                case 0: {
                    System.out.println("Program terminated successfully !!");
                    System.exit(1);
                }
                default: {
                    System.out.println("Entered wrong choice !!\nProgram terminated !!");
                }
            }

        }while(choice != 0);

    }
}
