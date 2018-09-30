import java.io.*;
import java.util.*;

public class Recursivelcs{
  public static int lcs(int i, int j, String x, String y){
    if(i>=x.length() || j>=y.length()){
      return 0;
    }
    if(x.charAt(i)==y.charAt(j)){
      return 1+lcs(i+1, j+1, x, y);
    }
    else{
      return Math.max(lcs(i+1, j, x, y), lcs(i, j+1, x, y));
    }
  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String s = br.readLine().trim();
      String r = br.readLine().trim();
      System.out.println(""+lcs(0, 0, s, r));
    }
}
