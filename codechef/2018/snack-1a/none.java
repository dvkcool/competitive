import java.io.*;
import java.util.*;

public class none{
  static int checkP(int a, int b, long c){
    long start = (long) Math.pow(2, Math.min(a, b));
    int r =0;
    while(start<c){
      if(noOne(start)==a){
        long d = c - start;
        if(noOne(d)==b){
          r++;
        }
      }
      else if(noOne(start)==b){
        long d = c - start;
        if(noOne(d)==a){
          r++;
        }
      }
      else{
      }
      start++;
    }
    return r;
  }
  static int noOne(long n){
        int count = 0;
        while (n != 0){
            if(n % 2 != 0){
              count++;
            }
            n /= 2;
        }
        return count;
  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        long a = Long.parseLong(s[0]);
        long b = Long.parseLong(s[1]);
        long c = Long.parseLong(s[2]);
        int na = noOne(a);
        int nb = noOne(b);
        System.out.println(""+checkP(na, nb, c));
      }
    }
}
/*
2
2
2 3
2
2 4
3
3
-1 -1 1
4
4 6 7 -1
5
1 -1 3 -1 1

2
4
4 6 7 -1
5
1 -1 -1 4 1
