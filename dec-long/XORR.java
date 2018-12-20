import java.io.*;
import java.util.*;

public class XORR{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      while(true){
        String s[] = br.readLine().trim().split(" ");
        int a = Integer.parseInt(s[0]);
        int b = Integer.parseInt(s[1]);
        int c= Integer.parseInt(s[2]);
        System.out.println(""+((a^b)^c));
      }
    }
}
