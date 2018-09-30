import java.io.*;
import java.util.*;

public class Main{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine());
      for(int i=0; i<cases; i++){
          String s[] = br.readLine().split(" ");
          int n = Integer.parseInt(s[0]);
          int q = Integer.parseInt(s[1]);
          int a[] = new int[n];
          float b[] = new float[n];
          String att[] = br.readLine().split(" ");
          String btt[] = br.readLine().split(" ");
          int result = 0;
          for(int j=0; j<n; j++){
            b[j] = Float.parseFloat(btt[j]);
            if(b[j] == Float.parseFloat(att[j])){
              result++;
            }
            a[j] = result;
          }
          for(int j=0; j<q; j++){
            String mt[] = br.readLine().split(" ");
            int l = Integer.parseInt(mt[0]);
            int r = Integer.parseInt(mt[1]);
            int qw = Integer.parseInt(mt[2]);
            l = l ^ result;
            r = r ^ result;
            result = 0;
            if(l<1){
              l=1;
            }
            for(int k=l-1; (k<r && k>=0) && k<n; k++){
              if(b[k] == qw){
                result++;
              }
            }
            if(l>1){
              result += a[l-1];
            }
            if(r<(n-1)){
              result = result + a[n-1] - a[r];
            }
            System.out.println(""+result);
          }
        }

      }

}
