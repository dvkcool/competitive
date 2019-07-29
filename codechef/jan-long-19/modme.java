import java.io.*;
import java.util.*;

public class modme{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int ip=1; ip<=cases; ip++){
        String s[] = br.readLine().trim().split(" ");
        long n = Long.parseLong(s[0]);
        long p = Long.parseLong(s[1]);
        long ek = (n/2) +1;
        long max = n%ek;
        long ne = p - max;
        long np = p - n;
        long result = 0;
        if(n==1 || n==2){
          result = p * p * p;
          System.out.println(""+result);
          continue;
        }
        result = ne * ne;
        if(np>0){
          result  = result + (np*np) + (np*ne);
        }
        /*
        int count =0;
        for(int i=100; i>0; i--){
          for(int j=100; j>0; j--){
            for(int k=100; k>0; k--){
              long l = (((n%i)%j)%k)%n;
              if(l==0){
                continue;
              }
              if(l==max){
                count++;
              }
              //System.out.println("n: "+n+" i: "+i+" j: "+j+" k: "+k+" ans: "+l);
            }
          }
        }
        if(count != result){
          System.out.println(" fail: max: "+count+" result: "+ result+" i: "+ip);
        }
        */
        System.out.println(""+result);
      }
    }
}
