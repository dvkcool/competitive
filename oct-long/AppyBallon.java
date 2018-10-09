import java.io.*;
import java.util.*;
public class AppyBallon{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String s[] = br.readLine().trim().split(" ");
      int n = Integer.parseInt(s[0]);
      long m = Long.parseLong(s[1]);
      String sa[] = br.readLine().trim().split(" ");
      String sb[] = br.readLine().trim().split(" ");
      Vector v = new Vector();
      long sum = 0;
      for(int i=0; i<n; i++){
        int a = Integer.parseInt(sa[i]);
        int b = Integer.parseInt(sb[i]);
        int j = 1000;
        int k = (int) m;
        sum += a;
        while(a>0 && (j>0 && k>0)){
          long d = a *b;
          a--;
          j--;
          k--;
          v.add(d);
        }
      }
      if(m>sum){
        System.out.println("0");
      }
      else{
        Comparator comparator = Collections.reverseOrder();
        Collections.sort(v,comparator);
        int t = (int) m;
        System.out.println(""+v.elementAt(t));
      }



    }
}
