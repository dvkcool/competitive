import java.io.*;
import java.util.*;

public class snackp{
  public static void main(String args[] ) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(br.readLine().trim());
        for(int i=0; i<cases; i++){
          int n = Integer.parseInt(br.readLine().trim());
          String s[] = br.readLine().trim().split(" ");
          long b[] = new long[s.length];
          long c = 1;
            for(int j=0; j<s.length; j++){
              b[j] = Long.parseLong(s[j]);
              if(j!=0){
                b[j] += b[j-1];
              }
            }
              for(int k=0; k<s.length; k++){
                int d = (int) c;
                int e = n - d;
                if(e<0){
                  System.out.println(""+k);
                  break;
                }
                else if(e>0){
                  if(e<=b[d]){
                    k++;
                    System.out.println(""+k);
                    break;
                  }
                  else{
                    c = c + b[d];
                  }
                }
                else{
                  System.out.println(""+k);
                  break;
                }
              }
        }
    }
}
