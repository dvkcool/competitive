import java.io.*;
import java.util.*;

public class MakepemSepCook{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int t = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<t; i++){
        int n = Integer.parseInt(br.readLine().trim());
        int a[] = new int[n];
        int v[] = new int[n];
        String s[] = br.readLine().trim().split(" ");
        for(int j=0; j<n; j++){
          a[j] = Integer.parseInt(s[j]);
          if(a[j]<=n)
          if(v[a[j]-1] == 0){
            v[a[j]-1] = 1;
          }
        }
        int result = 0;
        for(int j=0; j<n; j++){
          if(v[j] == 0){
            result++;
          }
        }
        System.out.println(""+result);
      }
    }
}
