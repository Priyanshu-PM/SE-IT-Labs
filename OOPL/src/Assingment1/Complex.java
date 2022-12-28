//  Name : Priyanshu Mahukhaye
//  Roll no : 23385
//  Assignment no 1

package Assingment1;
import java.util.*;

public class Complex {
    private
    int real, imaginary;

    public
    Complex() {

    }
    Complex(int tempreal, int tempimaginary) {
        real = tempreal;
        imaginary = tempimaginary;
    }

    public static Complex createComplex() {
        Scanner sc = new Scanner(System.in);
        int tempreal, tempimaginaru;
        System.out.print("Enter the real part : ");
        tempreal = sc.nextInt();
        System.out.print("Enter the imaginary part : ");
        tempimaginaru = sc.nextInt();

        return new Complex(tempreal, tempimaginaru);
    }

    static String addComplex(Complex c1, Complex c2) {

        StringBuilder sb = new StringBuilder();
        sb.append((c1.real + c2.real)+" + i"+(c1.imaginary + c2.imaginary));
        return sb.toString();
    }

    static String subComplex(Complex c1, Complex c2) {
        StringBuilder sb = new StringBuilder();
        sb.append((c1.real - c2.real)+" + i"+(c1.imaginary - c2.imaginary));
        return sb.toString();
    }

    static String mulComplex(Complex c1, Complex c2) {
        StringBuilder sb = new StringBuilder();
        sb.append(((c1.real*c2.real) - (c1.imaginary*c2.imaginary) + " + i"+((c1.real*c2.imaginary) + (c1.imaginary*c2.real))));
        return sb.toString();
    }

    static String divComplex(Complex c1, Complex c2) {
        StringBuilder sb = new StringBuilder();
        long term1 = ((c1.real*c2.real)+(c1.imaginary*c2.imaginary))/(c2.real*c2.real + c2.imaginary*c2.imaginary);
        long term2 = ((c1.imaginary*c2.real) - (c1.real*c2.imaginary))/(c2.real*c2.real + c2.imaginary*c2.imaginary);

        sb.append(term1 + " + i"+term2);

        return sb.toString();
    }

}
