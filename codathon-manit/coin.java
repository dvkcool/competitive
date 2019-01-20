import java.io.*;
import java.util.*;


class coin {
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
       // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
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

        //bw.append(result+"\n");
        for(int j =0; j<r; j++){
            int p = s.nextInt();
            int cc = s.nextInt();
            if(cc<=k){
                int rr = p-1;
                a[rr]++;
                continue;
            }
            int rtr = cc % (m + k-1);
            int rr = 0;
            if(rtr ==0){
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
        int max = Integer.MIN_VALUE;;
        int maxi = -1;
        for(int j=0; j<m; j++){
            int rw = j;
            for(int l = m; l>0; l--){
                    b[rw] += (l*a[j]);
                    rw = (rw+1)%m;
                    if(j==(m-1)){
                      if(b[rw]>max){
                        max = b[rw];
                        maxi = rw + 1;
                      }
                    }
            }
        }
        bw.append(maxi+" "+max+"\n");
      }
      bw.flush();
      bw.close();

    }
}
