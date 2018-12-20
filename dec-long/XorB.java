import java.io.*;
import java.util.*;

public class XorB{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int n = Integer.parseInt(br.readLine().trim());
        System.out.print("1 1 2 3\n");
        int r = Integer.parseInt(br.readLine().trim());
        if(r==-1){
          continue;
        }
        int j = r%10;
        if(j==0||j==2||j==4||j==6||j==8){
          System.out.print("2");
          for(int k=1; k<n; k++){
            System.out.print(" "+(r+k));
          }
          System.out.print(" "+(r+n)+"\n");
          int rt = Integer.parseInt(br.readLine().trim());
          if(rt==-1){
            return;
          }
          continue;
        }
        else if(j==5||j==7||j==9||j==1||j==3){
          r = r-4;
          System.out.print("2");
          for(int k=1; k<n; k++){
            System.out.print(" "+(r+k));
          }
          System.out.print(" "+(r+n)+"\n");
          int rt = Integer.parseInt(br.readLine().trim());
          if(rt==-1){
            return;
          }
          continue;
        }
      }
    }
}
