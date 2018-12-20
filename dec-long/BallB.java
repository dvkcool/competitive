import java.io.*;
import java.util.*;

public class BallB{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int n = Integer.parseInt(br.readLine().trim());
        int a[] = new int[n+1];
        int b[] = new int[5];
        HashSet<Integer> vt = new HashSet<Integer>();
        int pj=0;
        for(int j=1; j<=n; j++){
          if(pj==5){
            break;
          }
          if(a[j]==0){
            b[pj] = j;
            pj++;
          }
        }
        while(pj!=1){
          if(pj==3){
            String y[] = new String[3];

            System.out.print("?");
            int yr = 0;
            Iterator<Integer> it = vt.iterator();
            while (it.hasNext()){
              System.out.print(" "+it.next());
              yr++;
              if(yr==3){
                break;
              }
            }
            System.out.print("  "+b[0]+" "+b[1]+"\n");
            y[0] = br.readLine().trim();
            System.out.print("?");
            yr = 0;
            it = vt.iterator();
            while (it.hasNext()){
              System.out.print(" "+it.next());
              yr++;
              if(yr==3){
                break;
              }
            }
            System.out.print("  "+b[2]+" "+b[1]+"\n");
            y[1] = br.readLine().trim();
            System.out.print("?");
            yr = 0;
            it = vt.iterator();
            while (it.hasNext()){
              System.out.print(" "+it.next());
              yr++;
              if(yr==3){
                break;
              }
            }
            System.out.print("  "+b[0]+" "+b[2]+"\n");
            y[2] = br.readLine().trim();

            if(y[0].equals(y[1])){
              System.out.print("! "+b[1]+"\n");
              return;
            }
            else if(y[1].equals(y[2])){
              System.out.print("! "+b[2]+"\n");
              return;
            }
            else if(y[0].equals(y[2])){
              System.out.print("! "+b[0]+"\n");
              return;
            }
          }

          Iterator<Integer> it = vt.iterator();
          while (it.hasNext() && pj<5){
            b[pj] = it.next();
            pj++;
          }
          System.out.print("? "+b[0]+" "+b[1]+" "+b[2]+" "+b[3]+" "+b[4]+"\n");
          String s[] = br.readLine().trim().split(" ");
          int bbr[] = new int[2];
          bbr[0] = Integer.parseInt(s[0]);
          bbr[1] = Integer.parseInt(s[1]);
          a[bbr[0]] =1;
          a[bbr[1]] =1;
          vt.add(bbr[0]);
          vt.add(bbr[1]);
          pj=0;
          for(int j=1; j<=n; j++){
            if(pj==5){
              break;
            }
            if(a[j]==0){
              b[pj] = j;
              pj++;
            }
          }
        }
        if(pj==1){
          System.out.print("! "+b[0]+"\n");
        }
      }
    }
}
