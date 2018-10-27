import java.io.*;
import java.util.*;

public class thfr{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        int x = Integer.parseInt(s[0]);
        int y = Integer.parseInt(s[1]);
        int z = Integer.parseInt(s[2]);
        if((x-y-z)==0){
          System.out.println("yes");
          continue;
        }
        else if((y-x-z)==0){
          System.out.println("yes");
          continue;
        }
        else if((z-x-y)==0){
          System.out.println("yes");
          continue;
        }
        else{
          System.out.println("no");
        }
      }
    }
}
