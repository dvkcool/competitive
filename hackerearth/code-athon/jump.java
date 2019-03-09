/*
 * Enter your code here. Read input from STDIN. Print your output to STDOUT.
 * Your class should be named CandidateCode.
*/

import java.io.*;
import java.util.*;
public class CandidateCode {
  static int r= 1;
  static int JumpCalc(int x, int y, int h){
    if(h<=x){
      return 1;
    }
    r = h/x;
    r--;
    h = h - r*(x-y);
    while(true){
      if(h<=0){
        break;
      }
      else if(h<=x){
        r++;
        break;
      }
      else{
        h = h - x + y;
        r++;
      }
    }
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
