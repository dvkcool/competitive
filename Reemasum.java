import java.io.*;
import java.util.*;

public class Reemasum{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int t = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<t; i++){
        int n = Integer.parseInt(br.readLine().trim());
        int a[] = new int[n];
        String s[] = br.readLine().trim().split(" ");
        int result =0;
        int prevsum = 0;
        for(int j=0; j<n; j++){
          if(s[j].charAt(0) == '1' && 1 <= 2*n){
            result++;
            if(j==0){
              prevsum = 1;
            }
            else if(j<n-1){
              if(s[j+1].charAt(0) == '2'){
                prevsum = prevsum+2;
                if(prevsum<2*n){
                  result++;
                }
              }
            }
          }
          if(s[j].charAt(0) == '2' && 2 <= 2*n){
            result++;
            if(j==0){
              prevsum = 2;
            }
            else if(j<n-1){
              if(s[j+1].charAt(0) == '1'){
                prevsum = 2;
              }
              else{
                prevsum = prevsum+2;
                if(prevsum<2*n){
                  result++;
                }
              }
            }
          }
        }

        System.out.println(""+result);
      }
    }
}
