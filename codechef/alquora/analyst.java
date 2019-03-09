/* Read input from STDIN. Print your output to STDOUT*/

import java.io.*;
import java.util.*;
public class CandidateCode {
    public static void noOfValid(Vector v, int k){
      int count = 0;
      while(k>0){
        k--;
        Object obj = Collections.min(v);
        int i = Integer.parseInt(""+obj);
        v.remove(obj);
        double d = i;
        if(i%2==0){
          d = d/2;
          while(i%2==0){
            i= i/2;
          }
        }
        for (int j = 3; j <= Math.sqrt(i); j+= 2){
          if(i%j == 0){
            d = d * (1 - 1/j);
            while (i%j == 0){
                i /= j;
            }
          }
        }
        if (i > 2){
          d = d * (1 - 1/i);
        }
        if(d%2 == 0){
          count++;
        }
      }
      System.out.println(""+count);
    }
   public static void main(String args[] ) throws Exception {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    Vector v = new Vector(n);
    for(int i=0; i<n; i++){
        v.add(sc.nextInt());
    }
    int k = sc.nextInt();
    System.out.println(""+noOfValid(v, k));

   }
}
