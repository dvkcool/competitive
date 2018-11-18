import java.io.*;
import java.util.*;

public class snack{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s = br.readLine().trim();
        int j = Integer.parseInt(s);
        if(j==2010 ||j==2015 || j==2016 || j==2017 || j==2019){
          System.out.println("HOSTED");
        }
        else{
          System.out.println("NOT HOSTED");
        }
      }
    }
}
