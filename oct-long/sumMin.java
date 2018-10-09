import java.io.*;
import java.util.*;

public class sumMin{
  static int c[] = new int[10];
  public static int minsingle(long a, long b){
    long d = a +b;
    int min = singlesum(a);
    if(min == 1){
      return 1;
    }
    for(int i=2; i<=10; i++){
      int j = singlesum(a*i);
      if(j==1){
        return 1;
      }
      if(j<min){
        min = j;
      }
    }
    for(int i=1; i<=10; i++){
      int j = singlesum(d*i);
      if(j==1){
        return 1;
      }
      if(j<min){
        min = j;
      }
    }
    return min;
  }
  public static int sumdigit(long a){
    if(a<10){
      return (int) a;
    }
    int r = 0;
    while(a>0){
      r = (int) (r + a%10);
      a= a/10;
    }
    return r;
  }
  public static int singlesum(long a){
    if(a<10){
      return (int) a;
    }
    int r = 0;
    while(a>0){
      r = (int) (r + a%10);
      a= a/10;
    }
    if(r<10){
      return r;
    }
    return singlesum(r);
  }
  public static void checkmin(long n, long d, int mn){
        int cn = 0;
        while(true){
          int sum = sumdigit(n);
          int st = 1;
          while(sum>=10){
            sum = sumdigit(sum);
            st++;
          }
          if(sum==1){
            cn = cn+st;
            System.out.println("1 "+cn);
            return;
          }
          if(sum==mn){
            cn = cn+st;
            System.out.println(mn+" "+cn);
            return;
          }
          n = n +d;
          cn++;
        }
  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        long n = Long.parseLong(s[0]);
        long d = Long.parseLong(s[1]);
        //int mn = minsingle(n, d);
        c = new int[10];
        checkmin(n, d, mn);
      }
    }
}
