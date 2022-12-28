//  Name : Priyanshu Mahukhaye
//  Roll no : 23385
//  Assignment 4

package Assignment4;
import java.util.*;

abstract class Shape {
    int length, breadth;
    Scanner sc = new Scanner(System.in);
    Shape() { }
    Shape(int len, int bre) {
        length = len;
        breadth = bre;
    }
    abstract public void computeArea();
}

class Rectangle extends Shape {

//    @Override
    public void computeArea() {
        System.out.println("Enter the details of the rectangle\n1. length\n2. breadth");
        length = sc.nextInt();
        breadth = sc.nextInt();
        System.out.println("The area of the rectangle is : "+length*breadth);
    }
}

class Triangle extends Shape {

//    @Override
    public void computeArea() {
        System.out.println("Enter the details of the triangle\n1. height\n2. breadth");
        length = sc.nextInt();
        breadth = sc.nextInt();
        System.out.println("The area of the triangle is : "+0.5*length*breadth);
    }
}
