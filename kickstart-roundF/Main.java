import java.io.*;
import java.util.*;

public class Main{
  public static int checkanagram(String a, int j, int k, String b, int len){
    int achar[] = new int[26];
    for(int i=j; i<=k; i++){
      int c = (int) (a.charAt(i) - 'A');
      achar[c]++;
    }
    int l = k-j+1;
    for(int t=0; t<len; t++){
      int bchar[] = new int[26];
      for(int s =t; s<(t+l) && s<len; s++){
        int c = (int) (b.charAt(s) - 'A');
        bchar[c]++;
      }
      int c= 0;
      for(int i=0; i<26; i++){
        if(achar[i] <= bchar[i]){
          c++;
        }
        else{
          break;
        }
      }
      if(c==26){
        return 1;
      }
    }
    return 0;

  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=1; i<=cases; i++){
        int len = Integer.parseInt(br.readLine().trim());
        String a = br.readLine().trim();
        String b = br.readLine().trim();
        int result = 0;
        int bchar[] = new int[26];
        for(int j =0; j<len; j++){
          int c = (int) (b.charAt(j) - 'A');
          bchar[c]++;
        }
        for(int j=0; j<len; j++){
          int c = (int) (a.charAt(j) - 'A');
          if(bchar[c] !=0){
            for(int k=j; k<len; k++){
              if(checkanagram(a, j, k, b, len) == 1){
                result++;
              }

            }
          }
        }
        System.out.println("Case #"+i+": "+result);
      }
    }
}
