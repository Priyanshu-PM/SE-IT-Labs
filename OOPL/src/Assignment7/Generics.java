//  Name : Priyanshu Mahukhaye
//  Roll no : 23385
//  Assignment 7

package Assignment7;
import java.util.*;

public class Generics {

    static boolean isPrime(int num) {
        for(int i = 2; i <= num/2; i++) {
            if(num % i == 0) {
                return false;
            }
        }
        
        return true;
    }
    static <T> void countNums(String opt, T ele[]) {
        int even = 0, odd = 0, prime = 0, palin = 0;
        if(opt.equals("EVEN")) {
            for(T num: ele) {
                if(Integer.parseInt(num.toString()) % 2 == 0) {
                    even++;
                }
            }
            System.out.println("Total even : "+even);
        }

        if(opt.equals("ODD")) {
            for(T num: ele) {
                if(Integer.parseInt(num.toString()) % 2 != 0) {
                    odd++;
                }
            }
            System.out.println("Total odd : "+odd);
        }

        if(opt.equals("PRIME")) {
            for(T num: ele) {
                if(isPrime(Integer.parseInt(num.toString()))) {
                    prime++;
                }
            }
            System.out.println("Total prime : "+prime);
        }

        if(opt.equals("PALINDROME")) {
            for(T num: ele) {
                StringBuilder sb = new StringBuilder(num.toString());
                if(sb.toString().equals(sb.reverse().toString())) {
                    palin++;
                }

            }
            System.out.println("Total palindrome : "+palin);
        }
    }

}
