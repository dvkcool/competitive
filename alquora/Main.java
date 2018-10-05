import java.io.*;
import java.util.*;

public class Main{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int len = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<len; i++){
        int m = Integer.parseInt(br.readLine().trim());
        String s = br.readLine().trim();
        int c =0;
        for(int j=0; j<m; j++){
          if(s.charAt(j) == 'A' || s.charAt(j) == 'E' || s.charAt(j) == 'I' || s.charAt(j) == 'O' ||s.charAt(j) == 'U'){
            c++;
            }
          }
        if(c>=2){
          System.out.println("Yes");
        }
        else{
          System.out.println("No");
        }

      }
    }
}
