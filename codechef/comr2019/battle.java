import java.io.*;
import java.util.*;

public class battle{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String s[] = br.readLine().trim().split(" ");
      int a = Integer.parseInt(s[0]);
      int b = Integer.parseInt(s[1]);
      int c = Integer.parseInt(s[2]);
      if(a==0 && (b==0 && c==0)){
        System.out.println("0");
        return;
      }
      else if(a!=0 && (b!=0 && c!=0)){
        // only 1 will be left always
        System.out.println("1");
        return;
      }
      else if(a==0 && (b==0 && c!=0)){
        System.out.println(""+c);
        return;
      }
      else if(b==0 && (c==0 && a!=0)){
        System.out.println(""+a);
        return;
      }
      else if(a==0 && (c==0 && b!=0)){
        System.out.println(""+b);
        return;
      }

      // All zero, non zero over
      // Two zero over
      // One zero cases

      if(a==0){
        //b  will always win against c
        System.out.println(""+b);
        return;
      }
      if(b==0){
        System.out.println(""+c);
        return;
      }
      if(c==0){
        System.out.println(""+a);
        return;
      }



    }
}
