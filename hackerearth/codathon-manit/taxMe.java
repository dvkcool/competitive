import java.io.*;
import java.util.*;

public class taxMe{
  static class FastReader
{
    BufferedReader br;
    StringTokenizer st;

    public FastReader()
    {
        br = new BufferedReader(new
                 InputStreamReader(System.in));
    }

    String next()
    {
        while (st == null || !st.hasMoreElements())
        {
            try
            {
                st = new StringTokenizer(br.readLine());
            }
            catch (IOException  e)
            {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt()
    {
        return Integer.parseInt(next());
    }

    long nextLong()
    {
        return Long.parseLong(next());
    }

    double nextDouble()
    {
        return Double.parseDouble(next());
    }

    String nextLine()
    {
        String str = "";
        try
        {
            str = br.readLine();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        return str;
    }
}
  static long a[];
  static long e;
  static void calc(int n, long r){
    if(n<3){
      a[n] = a[n] +r;
      a[n] = a[n] %1000000007;
      return;
    }
    e = e + (((n%1000000007)*(r%1000000007))%1000000007);
    e = e %1000000007;
    r = r %1000000007;
    calc(n-3, ((r*3)%1000000007));
    calc(n-1, r);
  }
  public static void main(String args[] ) throws Exception {
      //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      FastReader s=new FastReader();
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = s.nextInt();
      for(int i=0; i<cases; i++){
        //String s[] = br.readLine().trim().split(" ");

        int er = s.nextInt();
        int f = s.nextInt();
        int g = s.nextInt();
        a = new long[3];
        e = 0;
        int n = s.nextInt();
        calc(n, 1);
        //long res  = (e*2)%1000000007 + ((a[0]*er)%1000000007) + ((a[1]*f)%1000000007) + ((a[2]*g)%1000000007);
        //res = res % 1000000007;
        //bw.append(res+"\n");
        e = (e*2)%1000000007;
        a[0] = a[0]%1000000007;
        a[1] = a[1]%1000000007;
        a[2] = a[2]%1000000007;
        bw.append(e+" "+a[0]+" "+a[1]+" "+a[2]+"\n");
      }
      bw.flush();
      bw.close();
    }
}
