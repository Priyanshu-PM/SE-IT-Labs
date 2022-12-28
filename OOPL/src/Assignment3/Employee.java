//  Name : Priyanshu Mahukhaye
//  Roll no : 23385
//  Assignment 3

package Assignment3;
import java.util.*;

public class Employee {

    public
    Scanner sc = new Scanner(System.in);
    String name, empId, email;
    double mobileNo;
    String position;
    double DA, netPay, basicPay, grossSalary, hra, pf, dra, stf;

    Employee(String type) {

        System.out.println("Enter the details of the "+type);
        System.out.println("======================================");
        System.out.print("Enter the name of the "+type+" : ");
        name = sc.nextLine();
        System.out.print("Enter the employee id of "+type+" : ");
        empId = sc.next();
        System.out.print("Enter the mobile number of the "+type+" : ");
        mobileNo = sc.nextDouble();
        System.out.print("Enter the email id of the "+type+" : ");
        email = sc.next();
        System.out.print("Enter the salary of the "+type+" : ");
        basicPay = sc.nextDouble();

    }
    void calculateSalary() {

        DA = 0.97*basicPay;
        hra = 0.10*basicPay;
        pf = 0.12*basicPay;
        stf = 0.01*basicPay;
        grossSalary = DA + hra + pf + stf;
        netPay = grossSalary - (pf+stf);

    }

    void generatePayslip() {
        System.out.println("\n\n============Employee pay slip=======");
        System.out.println("=====================================\n");
        System.out.println("Name                               : "+name);
        System.out.println("Position                           : "+position);
        System.out.println("Employee id                        : "+empId);
        System.out.println("Mobile no                          : "+mobileNo);
//        System.out.println("Email id                           : "+email);
        System.out.println("Gross salary                       : "+grossSalary);
        System.out.println("Direct allowance                   : "+DA);
        System.out.println("Home rental allowance              : "+hra);
        System.out.println("Provident Fund                     : "+pf);
        System.out.println("Staff club fund                    : "+stf);
        System.out.println("In hand salary                     : "+netPay);
        System.out.println("\n");

    }
}

class Programmer extends Employee {
    public
    Programmer(String pos) {
        super(pos);
        position = pos;
    }

}

class TeamLead extends Employee {
    public
    TeamLead(String pos) {
        super(pos);
        position = pos;
    }
}

class AssProjectManager extends Employee {
    public
    AssProjectManager(String pos) {
        super(pos);
        position = pos;
    }

}

class ProjectManager extends Employee {
    public
    ProjectManager(String pos) {
        super(pos);
        position = pos;
    }

}