import java.io.*;
import java.util.*;

public class Main{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int t = Integer.parseInt(br.readLine().trim());
        long a[] = new long[3];
        a[0] = 1;
        int j = 0;
        while(true){

          if(j>=t){
            break;
          }
          j = j +2;
          if(j>=t){
            break;
          }

          a[1] = a[0];
          a[0] = 0;
          j = j + 8;
          if(j>=t){
            break;
          }
          a[2] = a[1];
          a[1] = 0;
          j = j +16;
          if(j>=t){
            break;
          }
          a[0] = 2 * a[2];
          a[2] = 0;
        }
        System.out.println(""+a[0]+" "+a[1]+" "+a[2]);
      }
    }
}
