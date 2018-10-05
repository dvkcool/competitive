import java.io.*;
import java.util.*;

public class ChefCookTT{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        int score = Integer.parseInt(s[0]) + Integer.parseInt(s[1]);
        int k = Integer.parseInt(s[2]);
        int l = score /k;
        if(l%2 == 0){
          System.out.println("CHEF");
        }
        else{
          System.out.println("COOK");
        }
      }
    }
}
