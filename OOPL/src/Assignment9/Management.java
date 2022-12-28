import java.util.Scanner;

class Selling{
    String []products={"NoteBook","Pen","Pencil","File","Papers","Pouch","Scale","Eraser","Stapler","Mask"};
    int []prices={30,10,3,25,30,50,10,5,20,40};
    int []quantity={10,20,50,15,30,7,22,14,50};
    int []bp={20,6,1,10,20,20,2,1,15,40};
    String key;
    int con=0,n=0;
    double price=0;
    Scanner sc=new Scanner(System.in);
    int []nos=new int[10];
    void purchase(){
        String []cart= {"","","","","","","","","",""};
        Scanner sc=new Scanner(System.in);
        System.out.println("\n----------[ BUY ]----------");
        while(con==0) {
            System.out.print("Enter Product Name correctly to add to Cart = ");
            cart[n]+=sc.next();
            System.out.print("\nEnter Product Name correctly to add to Cart = ");
            nos[n]=sc.nextInt();
            n+=1;
            System.out.print("Press 0 to continue : ");
            con=sc.nextInt();
        }
        int n=0;
        while(n!=cart.length){
            for(int j=0;j<products.length;j++){
                if(cart[n].equalsIgnoreCase(products[j])){
                    price+=(prices[j]*nos[n]);
                    quantity[j]-=nos[n];
                    break;
                }
            }
            n++;
        }
    }

    String add,city,state;
    double tship;
    void shipping(){
        System.out.println("\n----------[ Shipping ]----------");
        System.out.print("Enter State : ");
        state=sc.nextLine();
        System.out.print("\nEnter city : ");
        city=sc.next();
        System.out.print("\nAddress : ");
        add=sc.nextLine();
        add=sc.nextLine();
        tship=price+300;
        System.out.println("Total Shipping Price after Adding Shipping : "+tship);
    }

}
class Inventory extends Selling {
    void showProducts(){
        System.out.println("\n----------[ Inventory List ]----------");
        for(int i=0;i<products.length;i++){
            System.out.println(products[i]+": Rs."+prices[i]);
        }
    }

    void displayInfo(){
        System.out.println("\n----------[ Product Information ]----------");
        System.out.print("\nEnter Product Name : ");
        key=sc.next();
        int flag=0;
        for(int i=0;i<products.length;i++){
            if(products[i].equalsIgnoreCase(key) ){
                System.out.println("Name : "+products[i]+"\nPrice : Rs."+prices[i]+"\nQuantity : "+quantity[i]);
                flag=1;
            }
        }
        if(flag==0){
            System.out.println("\nProduct "+key+" not Found");
        }
    }

    void balanceStock(){
        System.out.println("\n----------[ Stock Balance ]----------");
        for(int i=0;i<products.length;i++){
            System.out.println(products[i]+" : "+prices[i]);
        }
    }

    void profit(){
        System.out.println("\n----------[ Profit/Loss Sheet ]----------");
        for(int i=0;i<products.length;i++){
            System.out.println(products[i]+" : Rs."+(prices[i]-bp[i]));
        }
    }
}

public class Management {
    public static void main(String[] args) {
        int choice,con=0;
        Scanner sc=new Scanner(System.in);
        Inventory i=new Inventory();
        while(con==0){
            System.out.println("----------[ Inventory Management ]----------");
            System.out.println("\n0.Exit\n1.List of All Products\n2.Display Individual Product Information\n3.Purchase\n4.Balance Stock\n5.Profit and Loss Calculation");
            System.out.print("\nEnter Choice = ");
            choice=sc.nextInt();
            switch(choice){
                case 0:
                    con=1;
                    break;
                case 1:
                    i.showProducts();
                    break;
                case 2:
                    i.displayInfo();
                    break;
                case 3:
                   i.showProducts();
                   i.purchase();
                   i.shipping();
                   break;
                case 4:
                    i.balanceStock();
                    break;
                case 5:
                    i.profit();
                    break;
                default:
                    System.out.println("Invalid Input !!!!");
                    break;
            }
        }
    }
}