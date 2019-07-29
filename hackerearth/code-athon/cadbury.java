/*
 * Enter your code here. Read input from STDIN. Print your output to STDOUT.
 * Your class should be named CandidateCode.
*/

import java.io.*;
import java.util.*;
public class cadbury {
  static int a[][] = new int[201][201];
  static int calc(int l, int w){
    if(l==1){
        a[l][w] = w;
        return w;
    }
    if(w==1){
        a[l][w] = l;
        return l;
    }
    if(l<=0|| w<=0){
      return 0;
    }
    if(a[l][w] != 0){
        return a[l][w];
    }
    if(a[w][l] != 0){
        return a[w][l];
    }
    int e = l;
    l = l-w;
    if(l==0){
      return 1;
    }
    int u =l;
    int v = w;
    l = Math.max(u, v);
    w = Math.min(u, v);
    a[e][w] = 1 + calc(l, w);
    return a[e][w];
  }
    public static void main(String args[] ) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int m = Integer.parseInt(br.readLine().trim());
      int n = Integer.parseInt(br.readLine().trim());
      int p = Integer.parseInt(br.readLine().trim());
      int q = Integer.parseInt(br.readLine().trim());

      int total = 0;
      for(int i = m; i<=n; i++){
          for(int j=p; j<=q; j++){
              if(a[i][j]!=0){
                  total +=a[i][j];
                  continue;
              }
              if(a[j][i]!=0){
                  total +=a[j][i];
                  continue;
              }
              int l = Math.max(i, j);
              int w = Math.min(i, j);
              total += calc(l, w);
          }
      }
      System.out.println(""+total);
   }
}
