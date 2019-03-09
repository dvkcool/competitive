import java.io.*;
import java.util.*;

public class distan{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int n = Integer.parseInt(br.readLine().trim());
        double a[] = new double[n];
        double b[] = new double[n];
        String tp[] = br.readLine().trim().split(" ");
        for(int j=0; j<n; j++){
          a[j] = Double.parseDouble(tp[j]);
        }
        String tb[] = br.readLine().trim().split(" ");
        for(int j=0; j<n; j++){
          b[j] = Double.parseDouble(tb[j]);
        }

        if(a[0]!=0 || b[n-1]!=0){
          bw.append("No\n");
          continue;
        }
        else if(a[n-1] != b[0]){
          bw.append("No\n");
          continue;
        }
        else{
          int u =0;
          for(int j= 1; j<(n-1); j++){
            if(a[j]+b[j] < b[0]){
              bw.append("No\n");
              u = 1;
              break;
            }
          }
          if(u==1){
            continue;
          }
          for(int j= 1; j<(n-1); j++){
            if(a[j]+b[0] < b[j]){
              bw.append("No\n");
              u = 1;
              break;
            }
          }
          if(u==1){
            continue;
          }
          for(int j= 1; j<(n-1); j++){
            if(a[n-1]+b[j] < a[j]){
              bw.append("No\n");
              u = 1;
              break;
            }
          }
          if(u==1){
            continue;
          }
          for(int j= 1; j<(n-1); j++){
            if(a[j-1]+b[j] + b[j-1] < a[j]){
              bw.append("No\n");
              u = 1;
              break;
            }
          }
          if(u==1){
            continue;
          }
          for(int j= 1; j<(n-1); j++){
            if(b[j-1]+a[j] + a[j-1] < b[j]){
              bw.append("No\n");
              u = 1;
              break;
            }
          }
          for(int j= 1; j<n; j++){
            if(a[j]==0){
              bw.append("No\n");
              u = 1;
              break;
            }
          }
          if(u==1){
            continue;
          }
          for(int j= 0; j<(n-1); j++){
            if(b[j]==0){
              bw.append("No\n");
              u = 1;
              break;
            }
          }
          if(u==1){
            continue;
          }
          if(u==0){
            bw.append("Yes\n");
            continue;
          }
        }
      }
      bw.flush();
      bw.close();
    }
}
