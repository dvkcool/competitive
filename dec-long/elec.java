import java.io.*;
import java.util.*;

public class elec{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n, c;
      String s[] = br.readLine().trim().split(" ");
      n = Integer.parseInt(s[0]);
      c = Integer.parseInt(s[1]);
      int y = 1000;
      int l = 1;
      int h = n;
      System.out.println("1 1");
      int rt =  Integer.parseInt(br.readLine().trim());
      y--;
      if(rt==1){
        System.out.println("2\n3 1");
      }
      else{
        l++;
        while(true){
          if(l>h){
            break;
          }
          else if((h-l)<=y){
            for(int i=l; i<=h; i++){
              System.out.println("1 "+i);
              y--;
              int r =  Integer.parseInt(br.readLine().trim());
              if(r==1){
                y = y-c;
                System.out.println("2\n3 "+i);
                break;
              }
            }
            break;
          }
          else{
            int m = (l+h)/2;
            System.out.println("1 "+m);
            y--;
            int r =  Integer.parseInt(br.readLine().trim());
            if(r==0){
              l = m;
            }
            else{
              y = y-c;
              System.out.println("2");
              h = m;
              if((m-l)==1){
                System.out.println("3 "+m);
                break;
              }
            }
          }
        }
      }
    }
}
