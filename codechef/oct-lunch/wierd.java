import java.io.*;
import java.util.*;

public class wierd{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        HashMap<Integer, Integer> count = new HashMap<Integer, Integer>();
        int l = Integer.parseInt(br.readLine().trim());
        String s[] = br.readLine().trim().split(" ");
        for(int j=0; j<l; j++){
          int a = Integer.parseInt(s[j]);
          if (count.containsKey(a)) {
                count.put(a, count.get(a) + 1);
            }
            else {
                count.put(a, 1);
            }
        }
        int r = 0;
        for (Map.Entry entry : count.entrySet()) {
            int a = Integer.parseInt(""+entry.getKey());
            int b = Integer.parseInt(""+entry.getValue());
            int c = 0;
            if(count.containsKey(b)){
              c = count.get(b);
            }

            if(a==c){
              r++;
            }
        }
        r = r/2;
        System.out.println(""+r);
      }
    }
}
