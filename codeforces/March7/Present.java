import java.io.*;
import java.util.*;

public class Present{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String s[] = br.readLine().trim().split(" ");
      int n = Integer.parseInt(s[0]);
      int k = Integer.parseInt(s[1]);
      String st[] = br.readLine().trim().split(" ");
      int a[] = new int[k];
      int b[] = new int[k];
      int r = 0;
      for(int i=0; i<n; i++){
        int m = Integer.parseInt(st[i]);
        m = m%k;
        a[m]++;
      }
      /*
      System.out.println();
      for(int i=0; i<k; i++){
        System.out.println(" "+a[i]);
      }
      System.out.println();
      */
      r = r + a[0] - a[0]%2;
      for(int i=1; i<k; i++){
        if(a[i]==0){
          continue;
        }
        if(b[i]!=0){
          continue;
        }
        int j = k-i;
        if(i==j){
          r = r + a[i] - a[i]%2;
        }
        else{
          int t = Math.min(a[i], a[j]);
          r = r + (2*t);
          b[i] = 1;
          b[j] = 1;
        }

      }
      System.out.println(""+r);
    }
}
