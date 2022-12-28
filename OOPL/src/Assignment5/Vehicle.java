//  Name : Priyanshu Mahukhaye
//  Roll no : 23385
//  Assignment 5

package Assignment5;

interface Vehicle {
    public void gearChange(int g);
    public void speedUp();
    public void applyBrake();
    public void getStatus();
}

class Bicycle implements Vehicle {
    int gear = 0, speed = 15;

    public void gearChange(int g) {
        if(g > 0 && g < 6)
            gear = g;
        else
            System.out.println("Cant change gear");
    }
    public void speedUp() {
        speed += 10;
    }
//    @Override
    public void applyBrake() {
        if(speed-10>= 0) {
            speed -= 10;
            System.out.println("Brakes has been applied");
        }
        else {
            System.out.println("Can't apply brake");
        }
    }
    public void getStatus() {
        System.out.println("The speed of the bicycle is : "+speed+"\nThe bicycle is on : "+gear+" gear");
    }
}

class Car implements Vehicle {

    int gear = 0, speed = 30;

    public void gearChange(int g) {
        if(g > 0 && g < 6)
            gear = g;
        else
            System.out.println("Cant change gear");
    }
    public void speedUp() {
        speed += 10;
    }
//    @Override
    public void applyBrake() {
        if(speed-10>= 0) {
            speed -= 10;
            System.out.println("Brakes has been applied");
        }
        else {
            System.out.println("Can't apply brake");
        }
    }
    public void getStatus() {
        System.out.println("The speed of the Car is : "+speed+"\nThe Car is on : "+gear+" gear");
    }

}

class Bike implements Vehicle {

    int gear = 0, speed = 15;

    public void gearChange(int g) {
        if(g > 0 && g < 6)
            gear = g;
        else
            System.out.println("Cant change gear");
    }
    public void speedUp() {
        speed += 10;
    }
//    @Override
    public void applyBrake() {
        if(speed-10>= 0) {
            speed -= 10;
            System.out.println("Brakes has been applied");
        }
        else {
            System.out.println("Can't apply brake");
        }
    }
    public void getStatus() {
        System.out.println("The speed of the Bike is : "+speed+"\nThe Bike is on : "+gear+" gear");
    }

}