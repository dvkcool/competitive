import java.io.*;
import java.util.*;

public class Reswait{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        int k = Integer.parseInt(s[2]);
        int l = Integer.parseInt(s[3]);
        int t[] = new int[n];
        String h[] = br.readLine().trim().split(" ");
        for(int j=0; j<n; j++){
          t[j] = Integer.parseInt(h[j]);
        }
        Arrays.sort(t);
        int  mint = Integer.MAX_VALUE;
        int minp = 0;
        int cnt = m;
        int p =0;
        for(int y=0; y<=k; y++){
          for(int j=p; j<n; j++){
            if(t[j]>y){
              p = j;
              break;
            }
            else{
              cnt++;
            }
          }
          int pw =  cnt + 1 - y/l;
          int wt = 0;

          if(pw>0){
            int u = y/l;
            u = u *l;
            wt = pw*l - (y -u);
          }
          if(mint>wt){
            mint = wt;
            minp = y;
          }
        }
        System.out.println(""+minp);

      }
    }
}
