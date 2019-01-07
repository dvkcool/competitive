import java.io.*;
import java.util.*;

public class dpairs{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String s[] = br.readLine().trim().split(" ");
      int n = Integer.parseInt(s[0]);
      int m = Integer.parseInt(s[1]);
      int a[] = new int[n];
      int b[] = new int[m];
      int p = 1;
      String sa[] = br.readLine().trim().split(" ");
      String sb[] = br.readLine().trim().split(" ");
      HashSet<Integer> sea = new HashSet<>();
      HashSet<Integer> seb = new HashSet<>();
      for(int i=0; i<n; i++){
        a[i] = Integer.parseInt(sa[i]);
        sea.add(a[i]);
      }
      for(int i=0; i<m; i++){
        b[i] = Integer.parseInt(sb[i]);
        seb.add(b[i]);
      }
      int yr = -1;
      for(int i=0; i<n; i++){
        if (!seb.contains(a[i])){
            yr = i;
            for(int j=0; j<m; j++){
              System.out.println(i+" "+j);
            }
            break;
          }
      }

      for(int i=0; i<m; i++){
        if (!sea.contains(b[i])){
            for(int j=0; j<n; j++){
              if(j==yr){
                continue;
              }
              System.out.println(j+" "+i);
            }
            break;
          }
      }
      /*
      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          if(p >=(n+m)){
            return;
          }
          int y = a[i] + b[j];
          if (!set.contains(y)){
                set.add(y);
                System.out.println(i+" "+j);
                p++;
            }
        }
      }
      */

    }
}
