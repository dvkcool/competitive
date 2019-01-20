import java.io.*;
import java.util.*;

public class TestClass{
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
            long bt[] = new long[15];



        bt[0] = Long.parseLong("792903394");
        bt[1] =  Long.parseLong("51012639");
        bt[2] =  Long.parseLong("633283662");
        bt[3] =  Long.parseLong("849971500");
        bt[4] =  Long.parseLong("895455021");
        bt[5] =  Long.parseLong("688358408");
        bt[6] =  Long.parseLong("914794919");
        bt[7] =  Long.parseLong("686365049");
        bt[8] =  Long.parseLong("633283662");
        bt[9] =  Long.parseLong("745426514");
        bt[10] =  Long.parseLong("433784915");
        bt[11] = Long.parseLong("689029720");
        bt[12] = Long.parseLong("236279528");
        bt[13] =  Long.parseLong("686365049");
        bt[14] =  Long.parseLong("378710169");
      long b[] = new long[15];
        b[0] = Long.parseLong("623016582");
        b[1] =  Long.parseLong("740299351");
        b[2] =  Long.parseLong("419076819");
        b[3] =  Long.parseLong("170325468");
        b[4] =  Long.parseLong("279647453");
        b[5] =  Long.parseLong("902664035");
        b[6] =  Long.parseLong("548808039");
        b[7] =  Long.parseLong("838942359");
        b[8] =  Long.parseLong("419076819");
        b[9] =  Long.parseLong("449972921");
        b[10] =  Long.parseLong("352636949");
        b[11] = Long.parseLong("621780054");
        b[12] = Long.parseLong("349918756");
        b[13] =  Long.parseLong("838942359");
        b[14] =  Long.parseLong("869049740");
      for(int i=0; i<cases; i++){
        //String s[] = br.readLine().trim().split(" ");
        a[0] = s.nextInt();
        a[1] = s.nextInt();
        a[2] = s.nextInt();
        int n = s.nextInt();
        int r = n/9999;
        long w = 9999;

        while(r>0){
          e = ((((bt[0]*w - bt[1])%1000000007)*2) %1000000007) + ((bt[2]*a[0])%1000000007) + ((bt[3]*a[1])%1000000007) + ((bt[4]*a[2])%1000000007);
          e = e %1000000007;
          f = ((((bt[5]*(w+1) - bt[6])%1000000007)*2) %1000000007) + ((bt[7]*a[0])%1000000007) + ((bt[8]*a[1])%1000000007) + ((bt[9]*a[2])%1000000007);
          f = f %1000000007;
          g = ((((bt[10]*(w+2) - bt[11])%1000000007)*2) %1000000007) + ((bt[12]*a[0])%1000000007) + ((bt[13]*a[1])%1000000007) + ((bt[14]*a[2])%1000000007);
          g = g%1000000007;
          a[0] = e;
          a[1] = f;
          a[2] = g;
          w = w+9999;
          r--;
        }
        /*
        r = n/999;
        long w = 999;

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
          w = w+999;
          r--;
        }
        */
        int y = (n/9999)*9999 +2;
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
