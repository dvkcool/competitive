import java.io.*;
import java.util.*;

public class guessrt{
  static long modInverse(long a)
  {
    long m = 1000000007;
      long g = gcd(a, m);
      if (g != 1)
          return -1;
      else
      {
          // If a and m are relatively prime, then modulo inverse
          // is a^(m-2) mode m

    return   power(a, m - 2, m);
      }
  }

  // To compute x^y under modulo m
  static long power(long x, long y, long m)
  {
      if (y == 0)
          return 1;

      long p = power(x, y / 2, m) % m;
      p = (p * p) % m;

      if (y % 2 == 0)
          return p;
      else
          return (x * p) % m;
  }

  // Function to return gcd of a and b
  static long gcd(long a, long b)
  {
      if (a == 0)
          return b;
      return gcd(b % a, a);
  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        long n = Long.parseLong(s[0]);
        long k = Long.parseLong(s[1]);
        long m = Long.parseLong(s[2]);
        long p = 0;
        long q = 1;
        if(m==1){
          p = 1;
          q = n;
        }
        else{
          if(m%2==0){
            m = m-1;
            long ey = m/2 +1;
            long e = power(n-1, ey, 1000000007);
            long g = power(n, ey, 1000000007);
            p = (g%1000000007-e%1000000007)%1000000007;
            if(p<0){
              p = p+ 1000000007;
            }
            q = g;
            g = (g * (n+k))%1000000007;
            p = ((p*g)%1000000007 + (e*q)%1000000007)%1000000007;
            q = (q *g)%1000000007;
          }
          else{
            long ey = m/2 +1;
            long e = power(n-1, ey, 1000000007);
            long g = power(n, ey, 1000000007);
            p = (g%1000000007-e%1000000007)%1000000007;
            if(p<0){
              p = p+ 1000000007;
            }
            q = g;
          }
        }
        /*
        while(m>0){
          if(n>k && m>1){
            n = n -  (n/k) *k;
            m--;
            continue;
          }
          long t = q;
          q = (((q * lq)%1000000007) *n)%1000000007;
          p = ((((p * n)%1000000007) *lq)%1000000007 + (lp*q)%1000000007)%1000000007;
          lp = n-1;
          lq = n;
          m--;
          n = n+k;
        }
        */
        long y = gcd(p, q);
        p = p/y;
        q = q/y;
        long r = (modInverse(q) *(p%1000000007))%1000000007;
        bw.append(r+"\n");
      }
      bw.flush();
      bw.close();
    }
}
