import java.io.*;
import java.util.*;

public class chfar{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        int l = Integer.parseInt(s[0]);
        int k = Integer.parseInt(s[1]);
        String t[] = br.readLine().trim().split(" ");
        int r = 0;
        for(int j=0; j<l; j++){
          int u = Integer.parseInt(t[j]);
          if(u==1){
            r++;
          }
        }
        if((l-r)<=k){
          System.out.println("YES");
        }
        else{
          System.out.println("NO");
        }
      }
    }
}
