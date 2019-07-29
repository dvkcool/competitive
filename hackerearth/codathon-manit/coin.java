import java.io.*;
import java.util.*;


class TestClass {
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
    public static void main(String args[] ) throws Exception {
       FastReader s=new FastReader();
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = s.nextInt();
      for(int i=0; i<cases; i++){
        int m, r, k;
        int c;
        c = s.nextInt();
        m = s.nextInt();
        r = s.nextInt();
        k = s.nextInt();
        int a[] = new int[m];
        int b[] = new int[m];
        for(int j =0; j<r; j++){
            int p = s.nextInt();
            int cc = s.nextInt();
            int rtr = cc % (m + k-1);
            int rr = 0;
            if(cc<=k){
                rr = p-1;
            }
            else if(rtr ==0){
                rr  = (p-1 + m-1)%m;
            }
            else if(rtr<=k){
                rr = p-1;
            }
            else{
                rr = (rtr-k +p-1)%m;
            }
            a[rr]++;
        }
        int maxi = 0;
        for(int j=0; j<m; j++){
            b[j] = b[j] + m*a[j];
            int rw = j+1;
            for(int l = m-1; l>0 && rw<m; l--){
                    b[rw] += (l*a[j]);
                    b[j] += (rw-j)*a[rw];
                    rw++;

            }
            if(b[maxi]<b[j]){
                maxi = j;
            }
        }
        maxi++;
        bw.append(maxi+" "+b[maxi-1]+"\n");
      }
      bw.flush();
      bw.close();
    }
}
