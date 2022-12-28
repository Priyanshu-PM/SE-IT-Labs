//  Name : Priyanshu Mahukhaye
//  Roll no : 23385
//  Assignment 3

package Assignment3;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int choice = 0;
        do {
            System.out.println("Welcome to the Employee payslip generation program\n");
            System.out.println("1. for Programmer\n2. for TeamLead\n3. for Assistant Project Manager\n4. for Project Manager\n");
            System.out.print("Enter your choice : ");
            choice = sc.nextInt();

            switch(choice) {
                case 1:
                {
                    Programmer p1 = new Programmer("Programmer");
                    p1.calculateSalary();
                    p1.generatePayslip();
                    break;
                }

                case 2:
                {
                    TeamLead t1 = new TeamLead("TeamLead");
                    t1.calculateSalary();
                    t1.generatePayslip();
                    break;
                }

                case 3:
                {
                    AssProjectManager asp = new AssProjectManager("Assistant Project Manager");
                    asp.calculateSalary();
                    asp.generatePayslip();
                    break;
                }

                case 4:
                {
                    ProjectManager p1 = new ProjectManager("Project Manager");
                    p1.calculateSalary();
                    p1.generatePayslip();
                    break;
                }
                case 0: {
                    System.out.println("Program terminated successfully !!");
                    System.exit(1);
                }
                default: {
                    System.out.println("Enter correct choice !!");
                }
            }
        }while(choice != 0);
    }
}
