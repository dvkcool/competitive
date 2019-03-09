import java.io.*;
import java.util.*;

public class DSum{
  static int c[] = new int[10];
  public static int checklen(int a){
    int i = (int) (Math.log(a)/Math.log(2));
    if(Math.pow(2, i) > a){
      return i-1;
    }
    else{
      return i;
    }
  }
  public static void checkmin(long n, long d){
      int i = 0;
      Vector<Integer> v = new Vector<>();
      int j;
      j = (int) n;
      v.add(j);
      while(true){
        if(i>10000000){
          break;
        }
        j = v.elementAt(i);
        if(j<10){
          if(c[j]==0){
            c[j] = i;
          }
        }
        int dsum = sumdigit(j);
        v.add(dsum);
        int sum = (int) (j+d);
        v.add(sum);
        i++;
      }

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
        c = new int[10];
        checkmin(n, d);
        for(int j=1; j<10; j++){
          if(c[j]!=0){
            System.out.println(""+j+" "+checklen(c[j]));
            break;
          }
        }
      }
    }
}
