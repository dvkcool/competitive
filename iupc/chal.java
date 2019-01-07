import java.io.*;
import java.util.*;

public class chal{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        int n = Integer.parseInt(s[0]);
        int x = Integer.parseInt(s[1]);
        int y = Integer.parseInt(s[2]);
        double mn[] = new double[n];
        String st[] = br.readLine().trim().split(" ");
        for(int j=0; j<n; j++){
          mn[j] = Double.parseDouble(st[j]);
        }
        Arrays.sort(mn);
        double sumt[] = new double[n];
        double sum = mn[0];
        for(int j=1; j<n; j++){
          sumt[j] = sum;
          sum += mn[j];
        }
        double tes = 0;
        double min = Integer.MAX_VALUE;
        for(int j=0; j<n; j++){
          tes = (((j*mn[j])- sumt[j]) * y) - (((sum - sumt[j]) - (mn[j]*(n-j)))*x);
          if(tes<min && tes>=0){
            min = tes;
          }
          /*if(tes >= 0){
            int h = (int) tes;
            System.out.println(""+h);
            break;
          }
          */
        }
        int h = (int) min;
        System.out.println(""+h);


      }
    }
}
