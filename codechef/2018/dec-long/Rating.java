import java.io.*;
import java.util.*;

public class Rating{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String s[] = br.readLine().trim().split(" ");
      int cases = Integer.parseInt(s[0]);
      int r = Integer.parseInt(s[1]);
      for(int i=0; i<cases; i++){
        if(Integer.parseInt(br.readLine().trim())<r){
          System.out.println("Bad boi");
        }
        else{
          System.out.println("Good boi");
        }
      }
    }
}
