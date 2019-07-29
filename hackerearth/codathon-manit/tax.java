import java.io.*;
import java.util.*;




public class tax{
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
  static int a[];
  static long calc(int n){
    if(n<0){
      return 0;
    }
    if(n<3){
      return a[n];
    }
    return ((long) n*2 + calc(n-3)*3 + calc(n-1));
  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        a = new int[3];
        a[0] = Integer.parseInt(s[0]);
        a[1] = Integer.parseInt(s[1]);
        a[2] = Integer.parseInt(s[2]);
        int n = Integer.parseInt(br.readLine().trim());
        long r = calc(n);
        bw.append(r+"\n");
      }
      bw.flush();
      bw.close();
    }
}
