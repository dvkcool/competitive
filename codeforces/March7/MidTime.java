import java.io.*;
import java.util.*;

public class MidTime{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String s[] = br.readLine().trim().split(":");
      String t[] = br.readLine().trim().split(":");
      int a = Integer.parseInt(s[0]);
      int b = Integer.parseInt(s[1]);
      int c = Integer.parseInt(t[0]);
      int d = Integer.parseInt(t[1]);
      int y = a*60 + b;
      int z = c*60 +d;
      int r = (y+z)/2;
      int h = r/60;
      int m = r%60;
      if(h<10){
        System.out.print("0"+h);
        System.out.print(":");
        if(m<10){
          System.out.print("0"+m);
        }
        else{
          System.out.print(""+m);
        }
      }
      else{
        System.out.print(""+h);
        System.out.print(":");
        if(m<10){
          System.out.print("0"+m);
        }
        else{
          System.out.print(""+m);
        }
      }
      System.out.println();
    }
}
