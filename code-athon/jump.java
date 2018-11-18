/*
 * Enter your code here. Read input from STDIN. Print your output to STDOUT.
 * Your class should be named CandidateCode.
*/

import java.io.*;
import java.util.*;
public class jump {
  static int r= 1;
  static int JumpCalc(int x, int y, int h){
    r = 1;
    h = h - (x-y);
    r += h/(x-y);
    if(h%(x-y) > 1)
    r++;
    return r;
  }
    public static void main(String args[] ) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int x = Integer.parseInt(br.readLine().trim());
      int y = Integer.parseInt(br.readLine().trim());
      int n = Integer.parseInt(br.readLine().trim());
      int total = 0;
      for(int i=0; i<n; i++){
        int h = Integer.parseInt(br.readLine().trim());
        total += JumpCalc(x, y, h);
      }
      System.out.println(""+total);
   }
}
