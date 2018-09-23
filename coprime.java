/* Read input from STDIN. Print your output to STDOUT*/

import java.io.*;
import java.util.*;
public class CandidateCode {
    public static void noOfValid(double v[], int k){
      Arrays.sort(v);
      int count = 0;
      while(k>0){
        k--;

        double i  = v[k];

        double j = i;
        if(i%2 == 0){
            while(i%2 == 0)
                i /= 2;
            j -= j/2;
        }
        for (int n = 3; n * n <= i; n = n+2){
            if (i % n == 0) {
                while (i % n == 0)
                    i /= n;
                j -= j / n;
            }
        }
        if (i > 1)
            j -= j / i;
        if(j%2==0)
            count++;

      }
      System.out.println(""+count);
    }
   public static void main(String args[] ) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int cases = Integer.parseInt(br.readLine().trim());
    double arr[] = new double[cases];
    for(int i=0; i<cases; i++){
        arr[i] = Double.parseDouble(br.readLine().trim());
    }
    int k = Integer.parseInt(br.readLine().trim());
    noOfValid(arr, k);

   }
}
