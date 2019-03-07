import java.io.*;
import java.util.*;

public class Team{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine().trim());
      String st[] = br.readLine().trim().split(" ");
      int a[] = new int[n];
      int max =0;
      int prev = 0;
      int prevj = 0;
      for(int i=0; i<n; i++){
        a[i] = Integer.parseInt(st[i]);
      }
      Arrays.sort(a);
      for(int i=0; i<n; i++){
        if((a[i]-a[prevj])>5){
          continue;
        }
        int j = prevj+1;
        int d= prev-1;
        while(j<n){
          if((a[j]- a[i])>5){
            break;
          }
          j++;
          d++;
        }
        if(j>=n){
          j--;
        }
        prevj=j;
        d++;
        if(d>max){
          max = d;
        }
      }
      System.out.println(""+max);
    }
}
