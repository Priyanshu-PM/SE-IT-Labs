class Main {
    
    public
    
    void display(int a, int b) {
        a = a + 5;
        b = a + 3;
    }
    public static void main(String args[]) {

        int a = 10, b = 20;
        Main obj = new Main();
        System.out.println("The value of a is : "+a);
        System.out.println("The value of b is : "+b);

        System.out.println("The values after the function is called !!");
        obj.display(50, 30);
        System.out.println("The value of a is : "+a);
        System.out.println("The value of b is : "+b);


    }
}