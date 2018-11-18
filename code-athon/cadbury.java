/*
 * Enter your code here. Read input from STDIN. Print your output to STDOUT.
 * Your class should be named CandidateCode.
*/

import java.io.*;
import java.util.*;
public class cadbury {
    public static void main(String args[] ) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int m = Integer.parseInt(br.readLine().trim());
      int n = Integer.parseInt(br.readLine().trim());
      int p = Integer.parseInt(br.readLine().trim());
      int q = Integer.parseInt(br.readLine().trim());
      int a[][] = new int[201][201];
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
              int r = 0;
              int l = Math.max(i, j);
              int w = Math.min(i, j);
              while(true){
                  if(l==1){
                      r += w;
                      break;
                  }
                  if(w==1){
                      r += l;
                      break;
                  }
                  if(l<0|| w<0){
                    break;
                  }
                  if(a[l][w] != 0){
                      r+= a[l][w];
                      l = l-w;
                      l = Math.max(l, w);
                      w = Math.min(l, w);
                      continue;
                  }
                  if(a[w][l] != 0){
                      r+= a[w][l];
                      l = l-w;
                      l = Math.max(l, w);
                      w = Math.min(l, w);
                      continue;
                  }
                  l = l-w;
                  r++;
                  if(l==0){
                    break;
                  }
                  int u =l;
                  int v = w;
                  l = Math.max(u, v);
                  w = Math.min(u, v);
              }
              a[i][j] = r;
              total += r;
          }
      }
      System.out.println(""+total);
   }
}
