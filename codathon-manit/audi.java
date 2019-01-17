import java.io.*;
import java.util.*;

public class audi{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        long n = Long.parseLong(br.readLine().trim());
        long result = 0;
        for(long j =2; j<=n; j++){
          result = result + ((((j+1)%1000000007) * (Math.pow(2, (j-2))%1000000007))%1000000007);
        }
        result += 1;
        System.out.println(""+result);
      }
    }
}
