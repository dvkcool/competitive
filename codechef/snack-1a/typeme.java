import java.io.*;
import java.util.*;

public class typeme{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        HashMap<String, Integer> map = new HashMap<>();
        int n = Integer.parseInt(br.readLine().trim());
        int r = 0;
        for(int j=0; j<n; j++){
          String s = br.readLine().trim();
          if(map.containsKey(s)){
            Integer a = map.get(s);
            r = r + a/2;
            continue;
          }
          int x = 0;
          int y = -1;
          for(int k=0; k<s.length(); k++){
            char c = s.charAt(k);
            if(c=='d'||c=='f'){
              if(y==1){
                x = x + 4;
              }
              else{
                x = x + 2;
                y=1;
              }
            }
            else{
              if(y==2){
                x = x + 4;
              }
              else{
                x = x + 2;
                y=2;
              }
            }
          }
          r = r + x;
          map.put(s, x);
        }
        System.out.println(""+r);


      }
    }
}
