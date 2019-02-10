import java.io.*;
import java.util.*;

public class manhat{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int it=0; it<cases; it++){
        int A, m, n, x, y, a, b, c, d;
        a = 0; b=0; c = 0; d = 0; x = 0; y =0; A =0;
        System.out.println("Q 0 0");
        A = Integer.parseInt(br.readLine().trim());
        if(A==-1){
          break;
        }
        m = A;
        System.out.println("Q 1000000000 0");
        A = Integer.parseInt(br.readLine().trim());
        if(A==-1){
          break;
        }
        n = A;

        System.out.println("Q 0 1000000000");
        A = Integer.parseInt(br.readLine().trim());
        if(A==-1){
          break;
        }
        x = A ;
        System.out.println("Q 1000000000 1000000000");
        A = Integer.parseInt(br.readLine().trim());
        if(A==-1){
          break;
        }
        y = A;
        A = 1000000000 + m -n;
        A = A/2;
        System.out.println("Q "+A+" 0");
        A = Integer.parseInt(br.readLine().trim());
        if(A==-1){
          break;
        }
        b = A;
        a = m-b;
        c = (1000000000 + m -n - a);
        d= 1000000000 +a -x;
        System.out.println("A "+a+" "+b+" "+c+" "+d);
        A = Integer.parseInt(br.readLine().trim());
        if(A==-1){
          break;
        }
      }
    }
}
