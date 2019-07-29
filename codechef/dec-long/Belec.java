import java.io.*;
import java.util.*;

public class Main{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n, c;
      String s[] = br.readLine().trim().split(" ");
      n = Integer.parseInt(s[0]);
      c = Integer.parseInt(s[1]);
      int i = 1;
      while(i<=n){
        System.out.print("1 "+i+"\n");
        int r = Integer.parseInt(br.readLine().trim());
        if(r==-1){
          return;
        }
        else if(r == 1){
          if(i==1){
            System.out.print("2\n3 1\n");
            return;
          }
          else{
            int j = i-500+1;
            System.out.print("2\n");
            j = i-250;
            System.out.println("1 "+j+"\n");
            int rtt = Integer.parseInt(br.readLine().trim());
            if(rtt==1){
              System.out.print("2\n");
              i = j;
              j = j -250+1;
            }
            else if(rtt==-1){
              return;
            }
            else if(rtt==0){
              j++;
            }
            for(;j<i; j++){
              System.out.print("1 "+j+"\n");
              int rt = Integer.parseInt(br.readLine().trim());
              if(rt==1){
                System.out.print("2\n3 "+j+"\n");
                return;
              }
              else if(rt==-1){
                return;
              }
            }
            System.out.print("3 "+i+"\n");
            return;
          }
        }
        else{
          i = i+500;
        }
      }
      int j = i-500+1;
      for(;j<n; j++){
        System.out.print("1 "+j+"\n");
        int rt = Integer.parseInt(br.readLine().trim());
        if(rt==1){
          System.out.println("2\n3 "+j+"\n");
          return;
        }
        else if(rt==-1){
          return;
        }
      }
      System.out.println("3 "+n+"\n");
    }
}
