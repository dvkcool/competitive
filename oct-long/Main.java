import java.io.*;
import java.util.*;
 class PairA
{
    int a;
    int b;
    public PairA(int x, int y){
        this.a = x;
        this.b = y;
    }
}
class SortProduct implements Comparator<PairA>
{
    public int compare(PairA m, PairA n)
    {
        return ((m.a * m.b) - (n.a * n.b));
    }
}
public class Main{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String s[] = br.readLine().trim().split(" ");
      int n = Integer.parseInt(s[0]);
      long m = Long.parseLong(s[1]);
      ArrayList<PairA> ar = new ArrayList<PairA>();
      String sa[] = br.readLine().trim().split(" ");
      String sb[] = br.readLine().trim().split(" ");
      for(int i=0; i<n; i++){
        ar.add(new PairA(Integer.parseInt(sa[i]), Integer.parseInt(sb[i])));
      }
      Collections.sort(ar, new SortProduct());
      while(m>0){
        int q = ar.size();
        q = q-1;
        ar.set(q, new PairA(ar.get(q).a - 1, ar.get(q).b));
        m--;
        Collections.sort(ar, new SortProduct());
      }
      long max =0;
      for(int i=0; i<n; i++){
        long c = ar.get(i).a * ar.get(i).b;
        if(c>max){
          max=c;
        }
      }
      System.out.println(""+max);


    }
}
