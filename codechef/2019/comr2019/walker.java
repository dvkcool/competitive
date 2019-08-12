import java.io.*;
import java.util.*;

public class walker{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine().trim());
      char x[] = br.readLine().trim().toCharArray();
      char y[] = br.readLine().trim().toCharArray();
      String s[] = br.readLine().trim().split(" ");

      int a = Integer.parseInt(s[0]);
      int b = Integer.parseInt(s[1]);
      int c = Integer.parseInt(s[2]);
      int d = Integer.parseInt(s[3]);


      long r = 0;
      int p = Integer.MAX_VALUE;
      for(int i=0; i<x.length; i++){
        if(x[i]==y[i]){
          //same cases go away
          continue;
        }
        else if(x[i]=='1'){
          if(y[i]=='2'){
            //1-2
            p = a;
            p = Math.min(p, (b+c));
          }
          else{
            //1-3
            p = c;
            p = Math.min(p, (a+b));
          }
        }
        else if(x[i]=='2'){
          if(y[i]=='3'){
            //2-3
            p = b;
            p = Math.min(p, (a+c));
          }
          else{
            //2-1
            p = a;
            p = Math.min(p, (b+c));
          }
        }
        else if(x[i]=='3'){
          if(y[i]=='1'){
            //3-1
            p = c;
            p = Math.min(p, (a+b));
          }
          else{
            //3-2
            p = b;
            p = Math.min(p, (a+c));
          }
        }

        r = r + Math.min(p, d);

      }
      System.out.println(""+r);
    }
}
