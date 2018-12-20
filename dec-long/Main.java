import java.io.*;
import java.util.*;

public class Main{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      System.out.println("1");
      int y = Integer.parseInt(br.readLine().trim());
      int a[] = new int[3];
      a[0] = 1;
      a[y-1] = 1;
      for(int i=0; i<3; i++){
        if(a[i]!=1){
          i++;
          System.out.println(""+i);
          break;
        }
      }
    }
}
