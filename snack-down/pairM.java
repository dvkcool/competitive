import java.io.*;
import java.util.*;

public class pairM{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int len = Integer.parseInt(br.readLine().trim());
        String s[] = br.readLine().trim().split(" ");
        int a[] = new int[len];
        for(int j=0; j<len; j++){
          a[j] = Integer.parseInt(s[j]);
        }
        Arrays.sort(a);
        HashMap<Integer, Integer> hmap = new HashMap<Integer, Integer>();
        for (int j = 0; j < len; j++) {
            if (hmap.get(a[j]) == null) {
                hmap.put(a[j], 1);
            }
            else {
                int c = hmap.get(a[j]);
                hmap.put(a[j], ++c);
            }
        }
        int result = 0;
        for(int j=2; j<len; j +=2){
          int c = j/2;
          result = result + (c * hmap.get(a[j])) % 1000000007;
          result = result % 1000000007;
        }
        System.out.println(""+result);


      }
    }
}
