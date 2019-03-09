import java.io.*;
import java.util.*;

public class chefing{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int n = Integer.parseInt(br.readLine().trim());
        int a[][] = new int[n][26];
        for(int j=0; j<n; j++){
          String s = br.readLine().trim();
          for(int k=0; k<s.length(); k++){
            int d = s.charAt(k) - 'a';
            a[j][d]++;
          }
        }
        int r = 0;
        for(int j=0; j<26; j++){
          int w = 0;
          for(int p=0; p<n; p++){
            if(a[p][j]!=0){
              w++;
            }
          }
          if(w==n){
            r++;
          }
        }
        bw.append(r+"\n");
      }

      bw.flush();
      bw.close();
    }
}
