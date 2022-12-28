//  Name : Priyanshu Mahukhaye
//  Roll no : 23385
//  Assignment 7

package Assignment7;

public class Main {

    public static void main(String args[]) {

        Integer intArray[] = {1, 2, 4,5,6,7,8};
        Byte byteArray[] = {1, 3, 5,6,7, 2, 8,9, 11};
        Short shortArray[] = {1, 3, 6, 7, 8, 9, 121, 343, 787, 10};
        String arr[] = {"12", "23", "55", "767"};
        Generics.countNums("EVEN", intArray);
        Generics.countNums("ODD", byteArray);
        Generics.countNums("PRIME", shortArray);
        Generics.countNums("PALINDROME", shortArray);
        Generics.countNums("PALINDROME", arr);

    }
}
