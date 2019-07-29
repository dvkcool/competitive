import java.io.*;
import java.util.*;

public class rooks{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        StringBuilder result = new StringBuilder("");
        int r = 0;
        int n, k, leasta, leastb;
        char bre = '0';
        String t[] = br.readLine().trim().split(" ");
        n = Integer.parseInt(t[0]);
        k = Integer.parseInt(t[1]);
        int wa[] = new int[n];
        int wb[] = new int[n];
        for(int j=0; j<k; j++){
          String te[] = br.readLine().trim().split(" ");
          int na = Integer.parseInt(te[0]);
          int nb = Integer.parseInt(te[1]);
          wa[na-1] = 1;
          wb[nb-1] = 1;
        }
        leasta =0;
        leastb =0;
        for(int j=0; j<n; j++){
          if(wa[j]==0){
            leasta=j;
            break;
          }
          if(j==(n-1)){
            leasta = n;
            bw.append("0\n");
            bre = '1';
          }
        }
        if(bre=='1'){
          continue;
        }
        for(int j=0; j<n; j++){
          if(wb[j]==0){
            leastb=j;
            break;
          }
          if(j==(n-1)){
            leastb = n;
            bw.append("0\n");
            bre = '1';
          }
        }
        if(bre=='1'){
          continue;
        }
        while(leasta <n && leastb<n){
          r++;
          result.append((leasta+1)+" "+(leastb+1)+" ");
          wa[leasta]=1;
          wb[leastb] =1;
          int m = 0;
          if(leastb==(n-1) || (leasta==(n-1))){
            break;
          }
          for(int j=leasta+1; j<n; j++){
            if(wa[j]==0){
              leasta = j;
              break;
            }
            else if(j==(n-1)){
              leasta = n;
              bre='1';
            }
          }
          if(bre=='1'){
            break;
          }
          for(int j=leastb+1; j<n; j++){
            if(wb[j]==0){
              leastb = j;
              break;
            }
            else if(j==(n-1)){
              leastb = n;
              bre='1';
            }
          }
          if(bre=='1'){
            break;
          }
        }
        bw.append(r+" "+result+"\n");
      }
      bw.flush();
      bw.close();
    }
}
