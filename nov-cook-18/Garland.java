import java.io.*;
import java.util.*;

public class Garland{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        char a[] = new char[2];
        int rp[] = new int[2];
        String s = br.readLine().trim();
        int c = 0;
        int y = 0;
        int m = 0;
        int r =0;
        int g = 0;
        if(s.length() == 1){
          System.out.println("yes");
          y = 1;
          continue;
        }
        if(s.length() %2 ==1){
          System.out.println("no");
          continue;
        }
        for(int j =0; j<(s.length()-1); j++){
          if(s.charAt(j)=='R'){
            r++;
          }
          else{
            g++;
          }
          if(s.charAt(j)==s.charAt(j+1)){
            if(c==2){
              System.out.println("no");
              y=1;
              break;
            }
            a[c] = s.charAt(j);
            rp[c] = j;
            c++;
          }
        }
        if(s.charAt(s.length() -1 )== 'R'){
          r++;
        }
        else{
          g++;
        }
        if(s.charAt(0) == s.charAt(s.length()-1) && y==0){
          m =1;
          if(c==2){
            System.out.println("no");
            y=1;
            continue;
          }
          a[c] = s.charAt(0);
          rp[c] = 0;
          c++;
        }
        if(y==0){
          if(r!=g){
            System.out.println("no");
            continue;
          }
          int d = Math.abs(rp[1]-rp[0]);
          if(c!=0){
            if(d==0 || d== 1 || (d == (s.length() -2) && m==1)){
              System.out.println("no");
              continue;
            }
          }
          m = 2;
          if((c==2 && a[0]!=a[1]) || c==0){
            System.out.println("yes");
          }
          else if(a[0]==a[1] || c==1){
            System.out.println("no");

          }
          else{
            System.out.println("no");
          }
        }

      }
    }
}
