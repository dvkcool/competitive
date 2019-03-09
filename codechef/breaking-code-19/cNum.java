import java.io.*;
import java.util.*;

public class cNum{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      String s[] = br.readLine().trim().split(" ");
      int n = Integer.parseInt(s[0]);
      int m = Integer.parseInt(s[1]);
      String st[] = br.readLine().trim().split(" ");
      int a[][] = new int[n][m];
      int d[] = new int[m];
      int step = 0;
      for(int i=0; i<m; i++){
        int j = Integer.parseInt(st[i]);
        j--;
        for(int k=0; k<m; k++){
          if(a[j][k]==0){
            a[j][k]++;
            d[k]++;
            break;
          }
        }
        if(d[step]==n){
          bw.append("1");
          step++;
        }
        else{
          bw.append("0");
        }
      }
      bw.flush();
      bw.close();
    }
}
