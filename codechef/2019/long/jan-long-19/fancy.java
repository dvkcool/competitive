import java.io.*;
import java.util.*;

public class fancy{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s = br.readLine().trim();
        s = " " + s + " ";
        if(s.contains(" not ")){
          System.out.println("Real Fancy");
        }
        else{
          System.out.println("regularly fancy");
        }
      }
    }
}
