import java.io.*;
import java.util.*;

public class taxSmart{
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
      long e, f, g;
      long b[] = new long[15];
        b[0] = Long.parseLong("9299188169");
        b[1] =  Long.parseLong("372753004656");
        b[2] =  Long.parseLong("378266546");
        b[3] =  Long.parseLong("513702773");
        b[4] =  Long.parseLong("5595000");
        b[5] =  Long.parseLong("9304783169");
        b[6] =  Long.parseLong("373027159656");
        b[7] =  Long.parseLong("16785000");
        b[8] =  Long.parseLong("378266546");
        b[9] =  Long.parseLong("519297773");
        b[10] =  Long.parseLong("9824080942");
        b[11] = Long.parseLong("398992048306");
        b[12] = Long.parseLong("557893312");
        b[13] =  Long.parseLong("16785000");
        b[14] =  Long.parseLong("897564319");
      for(int i=0; i<cases; i++){
        //String s[] = br.readLine().trim().split(" ");
        a[0] = s.nextInt();
        a[1] = s.nextInt();
        a[2] = s.nextInt();
        int n = s.nextInt();
        int r = n/102;
        long w = 102;

        while(r>0){
          e = ((((b[0]*w - b[1])%1000000007)*2) %1000000007) + ((b[2]*a[0])%1000000007) + ((b[3]*a[1])%1000000007) + ((b[4]*a[2])%1000000007);
          e = e %1000000007;
          f = ((((b[5]*(w+1) - b[6])%1000000007)*2) %1000000007) + ((b[7]*a[0])%1000000007) + ((b[8]*a[1])%1000000007) + ((b[9]*a[2])%1000000007);
          f = f %1000000007;
          g = ((((b[10]*(w+2) - b[11])%1000000007)*2) %1000000007) + ((b[12]*a[0])%1000000007) + ((b[13]*a[1])%1000000007) + ((b[14]*a[2])%1000000007);
          g = g%1000000007;
          a[0] = e;
          a[1] = f;
          a[2] = g;
          w = w+51;
          r--;
        }
        int y = (n/102)*102 +2;
        solveMe(a, n, y);


        /*
        //long res  = (e*2)%1000000007 + ((a[0]*er)%1000000007) + ((a[1]*f)%1000000007) + ((a[2]*g)%1000000007);
        //res = res % 1000000007;
        //bw.append(res+"\n");
        e = (e*2)%1000000007;
        a[0] = a[0]%1000000007;
        a[1] = a[1]%1000000007;
        a[2] = a[2]%1000000007;
        bw.append(e+" "+a[0]+" "+a[1]+" "+a[2]+"\n");
        */
        long ew = a[n%3] % 1000000007;
        bw.append(ew+"\n");
      }
      bw.flush();
      bw.close();
    }
}
