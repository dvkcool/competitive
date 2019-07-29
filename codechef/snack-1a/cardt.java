import java.io.*;
import java.util.*;

public class cardt{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int n = Integer.parseInt(br.readLine().trim());
        String s[] = br.readLine().trim().split(" ");
        int a[] = new int[n];
        if(n==2){
          System.out.println("YES");
          continue;
        }
        a[0] = Integer.parseInt(s[0]);
        a[1] = Integer.parseInt(s[1]);
        int c = 0;
        for(int j=1; j<(n-1); j++){
          a[j+1] = Integer.parseInt(s[j+1]);
          if(a[j] < a[j-1]){
            if(a[j] > a[j+1]){
              c++;
            }
          }
          if(a[j-1] > a[j]){
            if(a[j] > a[j+1]){
              c++;
            }
          }
          if(c>1){
            System.out.println("NO");
            break;
          }
        }
        if(c<=1)
        System.out.println("YES");
      }
    }
}
