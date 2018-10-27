import java.io.*;
import java.util.*;

public class redc{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        int n = Integer.parseInt(s[0]);
        int k = Integer.parseInt(s[1]);
        String t[] = br.readLine().trim().split(" ");
        int result = 0;
        int a[] = new int[n];
        int b[] = new int[n];
        int c = 0;
        for(int j=0; j<n; j++){
           a[j] = Integer.parseInt(t[j]);
           b[j] = a[j];
        }
        int ty = 0;
        do{
          ty = 0;
          Arrays.sort(a);
          for(int j=0; j<n; j++){
            if(a[j]>k){
              ty++;
            }
          }
          if(ty==1 || ty==0){
            break;
          }
          for(int j=0; j<n; j++){
             if(a[j]>k){
               c=j;
               break;
             }
          }
          for(int j=c; j<(n-1); j +=2){
            if(a[j]>k){
              int rt = a[j]-k;
              a[j] = a[j] - rt;
              a[j+1] = a[j+1] - rt;
            }
          }
        }while(ty!=1);
        for(int j=0; j<n; j++){
          result += a[j];
        }
        do{
          ty = 0;
          Arrays.sort(b);
          for(int j=0; j<(n-1); j++){
            if(b[j]>k){
              ty++;
            }
          }
          if(ty==1 || ty==0){
            break;
          }
          for(int j=0; j<(n-1); j++){
             if(b[j]>k){
               c=j;
               break;
             }
          }
          b[c]--;
          b[n-2]--;
        }while(ty!=1);
        Arrays.sort(b);
        for(int j=0; j<(n-1); j++){
          if(b[j]>k){
            if(b[j+1]>k){
              int ry = b[j] -k;
              b[j] = k;
              b[j+1] = b[j+1] - ry;
            }
          }
        }
        int result2 = 0;
        for(int j=0; j<n; j++){
          result2 += b[j];
        }
        int ans = Math.max(result, result2);
        System.out.println(""+ans);
      }
    }
}
