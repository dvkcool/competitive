import java.io.*;
import java.util.*;

public class inxor{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int n = Integer.parseInt(br.readLine().trim());
        int a[] = new int[n];
        for(int j=0; j<n; j++){
            System.out.println("1 "+ (j+1) + " "+ (j+1) +" "+(j+1));
            int r = Integer.parseInt(br.readLine().trim());
            if(r==-1){
              return;
            }
            a[j] = r;
        }
        System.out.print("2");
        for(int j=0; j<n; j++){
          System.out.print(" "+a[j]);
        }
        int r = Integer.parseInt(br.readLine().trim());
        if(r==-1){
          return;
        }
      }
    }
}
