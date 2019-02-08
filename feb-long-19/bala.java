import java.io.*;
import java.util.*;

public class bala{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s = br.readLine().trim();
        int mapm[] = new int[26];
        int y = 0;
        for(int j=0; j<s.length(); j++){
          int d = s.charAt(j) - 'A';
          if(mapm[d] != 0){
            y++;
          }
          mapm[d]++;
        }
        if(y==0){
          bw.append("0\n");
          continue;
        }
        Arrays.sort(mapm);
        int summ[] = new int[26];
        int sum = 0;
        int c = 0;
        for(int j=0; j<26; j++){
          sum += mapm[j];
          if(c==0  && sum != 0){
            c = j;
          }
          summ[j] = sum;
        }
        int n = s.length();
        int mint = Integer.MAX_VALUE;
        for(int j=1; j<=Math.sqrt(n); j++){
          if(n%j==0){
            int k = n/j;
            if((c+j -1)<26 ){
              if(mint > summ[c+j-1]){
                mint = summ[c+j-1];
              }
            }
            if((c+k -1)<26 ){
              if(mint > summ[c+k-1]){
                mint = summ[c+k-1];
              }
            }
          }
        }
        bw.append(mint+"\n");
      }
      bw.flush();
      bw.close();
    }
}
