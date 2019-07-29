import java.io.*;
import java.util.*;

public class dragon{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      //BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        int n = Integer.parseInt(s[0]);
        int k = Integer.parseInt(s[1]);
        int m = Integer.parseInt(s[2]);
        String t[] = br.readLine().trim().split(" ");
        int a[] = new int[n];
        int max = Integer.MIN_VALUE;
        for(int j=0; j<n; j++){
          a[j] = Integer.parseInt(t[j]);
          if(a[j]>max){
            max = a[j];
          }
        }

        if((k*m)<max){
          System.out.println("-1");
          continue;
        }

        int jump = max/m;
        jump = Math.min(k, jump);
        int num = max/jump;
        num++;
        int burn[] = new int[num];
        for(int j=0; j<n; j++){
          int y = a[j]/jump;
          if(a[j]%jump==0 && a[j]!=0){
            y--;
          }
          burn[y]++;
        }
        max = Integer.MIN_VALUE;
        for(int j=0; j<num; j++){
          if(burn[j]>max){
            max = burn[j];
          }
        }
        System.out.println(""+max);
      }

    }
}
