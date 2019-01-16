import java.io.*;
import java.util.*;

public class copr{
  static boolean isPrime(int n) {
      if(n==2){
        return true;
      }
      //check if n is a multiple of 2
      if (n%2==0) return false;
      //if not, then just check the odds
      for(int i=3;i*i<=n;i+=2) {
          if(n%i==0)
              return false;
      }
      return true;
  }


  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int greatarr[] = new int[50000];
      int c= 0;
      int j = 13;
      while(c<50000){
        if(isPrime(j)){
          greatarr[c] = j;
          c++;
        }
        j += 2;
      }
      int cases = Integer.parseInt(br.readLine().trim());
      int prm[] = {2, 3, 5, 7, 11};
      for(int i=0; i<cases; i++){
        int n = Integer.parseInt(br.readLine().trim());
        int r =0;
        long a[] = new long[n];
        a[0] = 1;
        a[1] = 1;
        a[2] = 1;
        if(n>3){
          a[3] = 1;
        }
        int y = 0;
        for(int b=1; b<n; b++){
          if(a[b]==0){
            a[b] = greatarr[b-4];
          }
          if(b==(n-1)){
            r=3;
          }
          a[b-1] = a[b-1] * prm[r];
          a[b] = a[b] * prm[r];
          if(a[b] > 1000000000 || a[b-1] > 1000000000 ){
            System.out.println("-1");
            y = -1;
            break;
          }
          r++;
          if(r>=3){
            r = 0;
          }
        }
        if(y==-1){
          continue;
        }
        a[0] = a[0]* prm[4];
        a[n-1] = a[n-1] * prm[4];
        if(a[0] > 1000000000 || a[n-1] > 1000000000 ){
          System.out.println("-1");
          continue;
        }
        for(int b=0; b<n; b++){
          System.out.print(a[b]+" ");
        }
        System.out.println();
      }
    }
}
