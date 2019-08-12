import java.io.*;
import java.util.*;

public class AtmSepCook{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int t = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<t; i++){
        System.out.println("");
        String s[] = br.readLine().trim().split(" ");
        int n = Integer.parseInt(s[0]);
        int k = Integer.parseInt(s[1]);
        String arr[] = br.readLine().trim().split(" ");
        for(int j=0; j<n; j++){
          int a = Integer.parseInt(arr[j]);
          if(a<=k){
            k = k-a;
            System.out.print("1");
          }
          else{
            System.out.print("0");
          }
        }
      }

    }
}
