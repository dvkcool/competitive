import java.io.*;
import java.util.*;

public class mult{
  public static void maxprod(int n, int k){
    int a[] = new int[k];
    int c = 0;
    int j = n;
    if(k>n){
      System.out.println("-1");
      return;
    }
    if(k!=1){
      while(c<k){
        if(c!=0){
          c--;
          j = a[c];
          int y = c;
          c++;
          while(true){
            if(y>=0){
              j = a[y];
              if(j!=1){
                break;
              }
              y--;
            }else{
              break;
            }
          }
          if(y==-1){
            y=c-1;
          }
          while(true){
            if(y==k-1){
              break;
            }
            if(a[y]>=a[y+1]){
              break;
            }
            int temp = a[y];
            a[y] = a[y+1];
            a[y+1] = temp;
            y++;
          }

          if(j%2==0){
            if(j!=2){
              a[c] = j/2 +1;
              a[y] = j/2 -1;
              c++;
            }
            else{
              a[y] = 1;
              a[c] = 1;
              c++;
            }

           }
           else{
             a[y] = j/2;
             a[c] = j/2 +1;
             c++;
           }
        }
        else{
          if(j%2==0){
            if(j!=2){
              a[c] = j/2 - 1;
              c++;
              a[c] = j/2 + 1;
              c++;
            }
            else{
              a[c] = 1;
              c++;
              a[c] = 1;
              c++;
            }
           }
           else{
             a[c] = j/2;
             c++;
             a[c] = j/2 + 1;
             c++;
           }
        }

      }
    }
    else{
      a[0] = n;
    }
    long result = 1;
    for(int i=0; i<k; i++){
      result = result * a[i] * (a[i]-1);
      result = result %1000000007;
    }
    System.out.println(""+result);
  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        int n  = Integer.parseInt(s[0]);
        int k = Integer.parseInt(s[1]);
        maxprod(n, k);
      }
    }
}
