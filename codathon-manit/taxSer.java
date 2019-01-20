import java.io.*;
import java.util.*;

public class taxSer{
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

  /*
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
  */
  static void solveMe(long a[], int n, int p){
      if(p>=n){
          return;
      }
      for(int r = p+1; r<=n; r++){
          a[r%3] = r*2 + ((a[(r-3)%3] %1000000007) * 3) + (a[(r-1)%3]%1000000007);
          a[r%3] = a[r%3] % 1000000007;
      }
  }
  public static void main(String args[] ) throws Exception {
      //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      FastReader s=new FastReader();
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = s.nextInt();
      long a[] = new long[3];
        long e,f,g, u, v, w;
      for(int i=0; i<cases; i++){
        //String s[] = br.readLine().trim().split(" ");
        a[0] = s.nextInt();
        a[1] = s.nextInt();
        a[2] = s.nextInt();
        int n = s.nextInt();
        /*
        int r = n/51;
        while(r>0){
          e = 11182505 + ((378266546*a[0])%1000000007) + ((513702773*a[1])%1000000007) + ((5595000*a[2])%1000000007);
          e = e %1000000007;
          f = 643128717 + ((16785000*a[0])%1000000007) + ((378266546*a[1])%1000000007) + ((519297773*a[2])%1000000007);
          f = f %1000000007;
          g = 368481539 + ((557893312*a[0])%1000000007) + ((16785000*a[1])%1000000007) + ((897564319*a[2])%1000000007);
          g = g%1000000007;
          a[0] = e;
          a[1] = f;
          a[2] = g;
          r--;
        }
        int y = (n/51)*51 +2;
        solveMe(a, y, n);
        //long res  = (e*2)%1000000007 + ((a[0]*er)%1000000007) + ((a[1]*f)%1000000007) + ((a[2]*g)%1000000007);
        //res = res % 1000000007;
        //bw.append(res+"\n");
        e = (e*2)%1000000007;
        a[0] = a[0]%1000000007;
        a[1] = a[1]%1000000007;
        a[2] = a[2]%1000000007;
        bw.append(e+" "+a[0]+" "+a[1]+" "+a[2]+"\n");
        */

        e =0; f =0; g = 1;
        long m = 0;
        long ve = 0;
        int y = n;
        while(y>=3){
           m = m + g;
           ve = ve + (n-y)*g;
           y--;
           u = e;
           v = f;
           w = g;
           e = (w*3)%1000000007;
           f = u%1000000007;
           g = (v+w)%1000000007;

        }
        bw.append(m+" "+ve+" "+e+" "+f+" "+g+"\n");
        /*long ew = (m*2)%1000000007 + ((e*a[0])%1000000007) + ((f*a[1])%1000000007) + ((g*a[2])%1000000007);
        ew = ew %1000000007;
        bw.append(ew+"\n");
        */

      }
      bw.flush();
      bw.close();
    }
}
