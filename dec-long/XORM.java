import java.io.*;
import java.util.*;

public class XORM{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int n = Integer.parseInt(br.readLine().trim());
        int a, b, c, d, e, f;
        System.out.println("1 1 "+n+" "+(n-1));
        a = Integer.parseInt(br.readLine().trim());
        System.out.println("1 2 "+n+" "+(n-1));
        b = Integer.parseInt(br.readLine().trim());
        System.out.println("1 1 2 3");
        c = Integer.parseInt(br.readLine().trim());
        System.out.println("1 1 2 4");
        d = Integer.parseInt(br.readLine().trim());
        int wes[] = new int[n+1];
        int result[] = new int[n+1];
        result[3] = (a^b)^c;
        result[4] = (a^b)^d;
        wes[3] =1;
        wes[4] = 2;
        int qa =3;
        int qb =4;
        int y = 5;
        while(y<n){
          wes[qa] = wes[qa] -1;
          wes[qb] = wes[qb] - 1;
          System.out.println("1 "+qa+" "+qb+" "+y);
          int mr = Integer.parseInt(br.readLine().trim());
          result[y] = ((mr ^ result[qa])^result[qb]);
          wes[y] = 2;
          if(wes[qa]==0){
            for(int yu = qa +1; yu<=n; yu++){
              if(wes[yu]!=0){
                qa = yu;
                break;
              }
            }
          }
          if(wes[qb]==0 || qa == qb){
            for(int yu = qb +1; yu<=n; yu++){
              if(wes[yu]!=0 && yu!=qa){
                qb = yu;
                break;
              }
            }
          }
          y++;
        }
        System.out.println("1 3 "+(n-2)+" "+n);
        e = Integer.parseInt(br.readLine().trim());
        result[n] = (e^result[3])^result[n-2];
        result[1] = (a^result[n])^result[n-1];
        result[2] = (b^result[n])^result[n-1];
        y=1;
        System.out.print("2");
        while(y<=n){
          System.out.print(" "+result[y]);
          y++;
        }
        System.out.println();
        int yt =Integer.parseInt(br.readLine().trim());
        if(yt==-1){
          break;
        }
      }
    }
}
