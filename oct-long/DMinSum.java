import java.io.*;
import java.util.*;

public class DMinSum{
  public static void minsingle(long a, long b){
    int d = sumdigit(a);
    int n = 1;
    while(d>=10){
      d = sumdigit(d);
      n++;
    }
    if(d==1){
      System.out.println("1 "+n);
      return;
    }
    int dt;
    int nt;
    for(int i=1; i<11; i++){
      dt = sumdigit(a+(b*i));
      nt = i+1;
      while(dt>=10){
        dt = sumdigit(dt);
        nt++;
      }
      if(dt==1){
        System.out.println("1 "+nt);
        return;
      }
      if(dt<d){
        d= dt;
        n = nt;
      }
    }
    System.out.println(d+" "+n);
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
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        long n = Long.parseLong(s[0]);
        long d = Long.parseLong(s[1]);
        minsingle(n, d);
      }
    }
}
