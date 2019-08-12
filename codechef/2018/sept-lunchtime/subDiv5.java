import java.io.*;
import java.util.*;

public class subDiv5{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int len = Integer.parseInt(br.readLine().trim());
        int result =0;
        for(int j=0; j<len; j++){
          String s[] = br.readLine().trim().split(" ");
          int a = Integer.parseInt(s[0]);
          int b = Integer.parseInt(s[1]);
          if((b-a) >5)
          result++;
        }
        System.out.println(""+result);
      }


    }
}
