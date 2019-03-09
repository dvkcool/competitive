import java.io.*;
import java.util.*;

public class bala{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s = br.readLine().trim();
        int a[] = new int[26];
        int n = s.length();
        int e = 0;
        for(int j=0; j<n; j++){
          int d = s.charAt(j) - 'A';
          a[d]++;
          if(a[d]==1){
            e++;
          }
        }
        if(e==n){
          bw.append("0\n");
          continue;
        }
        Arrays.sort(a);
        int se = 0;
        int y = 0;
        int sum[] = new int[26];
        for(int j=0; j<26; j++){
          se += a[j];
          sum[j] = se;
        }
        int min = Integer.MAX_VALUE;
        for(int j=1; j<=Math.sqrt(n); j++){
          if(n%j==0){
            int k = n/j;
              int sumless;
              if(j<=26){
                if(j==26){
                  sumless = 0;
                }
                else{
                  sumless = sum[25-j];
                }
                int t = 0;
                for(int x=25; x>=0; x--){
                  if(a[x]>k){
                    t = t + a[x] -k;
                  }
                  else{
                    break;
                  }
                }
                if( (t+sumless) < min){
                  min = (t+sumless);
                }
              }
              if(k<=26 && k!=j){
                if(k==26){
                  sumless = 0;
                }
                else{
                  sumless = sum[25-k];
                }
                int t = 0;
                for(int x=25; x>=0; x--){
                  if(a[x]>j){
                    t = t + a[x] -j;
                  }
                  else{
                    break;
                  }
                }
                if( (t+sumless) < min){
                  min = (t+sumless);
                }
              }
          }
        }
        bw.append(min+"\n");
      }
      bw.flush();
      bw.close();
    }
}
