import java.io.*;
import java.util.*;

public class Main{
      static int partition(int a[], int b[], long d[], int l, int h){
        long pivot = d[h];
        int i = (l-1);
        for (int j=l; j<h; j++){
          long c = d[j];
            if (c <= pivot)
            {
                i++;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
                long t = d[i];
                d[i] = d[j];
                d[j] = t;
            }
        }
        int temp = a[i+1];
        a[i+1] = a[h];
        a[h] = temp;
        temp = b[i+1];
        b[i+1] = b[h];
        b[h] = temp;
        long t = d[i+1];
        d[i+1] = d[h];
        d[h] = t;

        return i+1;
    }
    static void MethodSort(int a[], int b[], long d[], int l, int h){
        if (l < h){
            int pi = partition(a, b, d, l, h);
            MethodSort(a, b, d, l, pi-1);
            MethodSort(a, b, d, pi+1, h);
        }
    }
    static void StableCheck(int a[], int b[], long d[], int n){
      int i = n-1;
      i--;
      if(i>0){
        if(d[i]<d[n-1]){
          return;
        }
      }
      while(i>=0){
        if(d[i]>d[n-1]){
          i--;
        }
        else{
          break;
        }
      }
      int tem = a[n-1];
      int temb = b[n-1];
      long dt = d[n-1];
      for(int j = n-1; j>i && j>0; j--){
        a[j] = a[j-1];
        b[j] = b[j-1];
        d[j] = d[j-1];
      }
      a[i+1] = tem;
      b[i+1] = temb;
      d[i+1] = dt;
    }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String s[] = br.readLine().trim().split(" ");
      int n = Integer.parseInt(s[0]);
      long m = Long.parseLong(s[1]);
      int a[] = new int[n];
      int b[] = new int[n];
      long d[] = new long[n];
      String sa[] = br.readLine().trim().split(" ");
      String sb[] = br.readLine().trim().split(" ");
      for(int i=0; i<n; i++){
        a[i] = Integer.parseInt(sa[i]);
        b[i] = Integer.parseInt(sb[i]);
        d[i] = a[i]*b[i];
      }
      MethodSort(a, b, d, 0, n-1);
      while(m>0){
        if(a[n-1]==0){
          break;
        }
        a[n-1] = a[n-1] -1;
        m--;
        d[n-1] -=b[n-1];
        if(m!=0)
        StableCheck(a, b, d, n);
      }
      int mi = n-1;
      for(int i=n-2; i>=0; i--)
      if(d[mi]<d[i]){
        mi = i;
      }

      System.out.println(""+d[mi]);


    }
}
