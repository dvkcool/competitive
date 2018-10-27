import java.io.*;
import java.util.*;

public class step{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        int l = Integer.parseInt(s[0]);
        int k = Integer.parseInt(s[1]);
        int r = 0;
        int prev = 0;
        String t[] = br.readLine().trim().split(" ");
        int j=0;
        while(j<l){
          int m  = Integer.parseInt(t[j]);
          j++;
          while((m-prev)>k){
            r++;
            prev += k;
          }
          if(prev<m){
            prev=m;
          }
        }
        System.out.println(""+r);
      }
    }
}
