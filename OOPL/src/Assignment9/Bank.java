// package Assignment9;
import java.util.Scanner;

class Money{
    final double limit=20000;
    double bal,wit,dep,lr=0;
    Scanner sc=new Scanner(System.in);
    void deposit(){
        System.out.print("Enter the Amount to Deposit = ");
        dep=sc.nextDouble();
        bal+=dep;
        System.out.println("Rs."+dep+" deposited Successfully!!!!");
    }

    void withdraw(){
        System.out.print("Enter the Amount to Withdraw = ");
        wit=sc.nextDouble();
        if(wit<=(bal-100)&&(lr+wit)<limit){
            bal-=wit;
            lr+=wit;
        }
        else if(lr+wit>=limit){
            System.out.println("Daily Withdrawal Limit Reached");
        }
        else{
            System.out.println("Insufficient Balance");
        }
    }

    void balance(){
        System.out.println("You Account Balance = Rs."+bal);
    }

}
class Account extends Money{
    String name,ano,sex,job,act,add,mm;
    int age;
    Scanner sc=new Scanner(System.in);
    void createAccount(){
        System.out.println("--------------[ Form Filling ]--------------");
        System.out.print("\nFull Name = ");
        name=sc.nextLine();
        System.out.print("\nGender (Male/Female/other) = ");
        sex=sc.next();
        System.out.print("\nAge = ");
        age=sc.nextInt();
        if(age>=18)
            mm="Adult";
        else
            mm="Minor";
        System.out.print("\nAadhar No = ");
        ano=sc.next();
        System.out.print("\nOccupation = ");
        job=sc.nextLine();
        job=sc.nextLine();
        System.out.print("\nAccount Type (Savings or Business) = ");
        act=sc.next();
        System.out.print("\nAddress = ");
        add=sc.nextLine();
        add=sc.nextLine();
        System.out.println("\nPlease Submit all the Following Documents to your nearest Demo Bank Branch");
        System.out.println("1.Aadhar Card\n2.Birth Certificate\n3.Occupation/School/College Document");
        System.out.println("\nAccount Created Successfully......");
    }

    void displayInformation(){
        System.out.println("--------------[ Account Information ]--------------");
        System.out.println("Full Name : "+name+"\tGender : "+sex);
        System.out.println("Aadhar No. : "+ano+"\t\tAge : "+age);
        System.out.println("Occupation : "+job+"\t\tType : "+mm);
        System.out.println("Account Type : "+act);
        System.out.println("Balance : Rs."+bal);
        System.out.println("Address : "+add);
    }
}

public class Bank {
    public static void main(String[] args) {
        int choice,con=0;
        Account a=new Account();
        Scanner sc=new Scanner(System.in);
        while(con==0) {
            System.out.println("-------------[ Bank Menu ]-------------");
            System.out.println("\n0.Exit\n1.Create Account\n2.Deposit Money\n3.Withdraw Money\n4.Check Balance\n5.Display Account Information");
            System.out.print("\nEntre Choice = ");
            choice = sc.nextInt();
            switch (choice) {
                case 0:
                    con=1;
                    break;
                case 1:
                    a.createAccount();
                    break;
                case 2:
                    a.deposit();
                    break;
                case 3:
                    a.withdraw();
                    break;
                case 4:
                    a.balance();
                    break;
                case 5:
                    a.displayInformation();
                    break;
                default:
                    System.out.println("Invalid Input !!");
                    break;
            }
        }
    }
}