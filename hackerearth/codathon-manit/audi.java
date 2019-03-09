import java.io.*;
import java.util.*;

public class audi{
    static long power(long x, long y, long p)
    {
        // Initialize result
        long res = 1;

        // Update x if it is more
        // than or equal to p
        x = x % p;

        while (y > 0)
        {
            // If y is odd, multiply x
            // with result
            if((y & 1)==1)
                res = (res * x) % p;

            // y must be even now
            // y = y / 2
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        long n = Long.parseLong(br.readLine().trim());
        long result = power(2, n-1, 1000000007) * (n%1000000007);
        result = result%1000000007;
        bw.append(result+"\n");
      }
      bw.flush();
      bw.close();
    }
}
