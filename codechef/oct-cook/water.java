import java.io.*;
import java.util.*;

public class water{
  static int result =0;
  public static void checkmax(int a[], int s, int e, int l){
    if(s<0 || e>=l){
      return;
    }
    if(s>=l || e<0){
      return;
    }
    if(s==e){
      return;
    }
    if(s>e){
      return;
    }
    result++;
    int max = a[s];
    int maxi = s;
    for(int i=s+1; i<=e; i++){
      if(max<a[i]){
        max = a[i];
        maxi = i;
      }
    }
    if(maxi > (e-maxi)){
      checkmax(a, maxi + 1, e, l);
    }
    else{
      checkmax(a, s, maxi - 1, l);
    }
  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int l = Integer.parseInt(br.readLine().trim());
        String s[] = br.readLine().trim().split(" ");
        int a[] = new int[l];
        result = 0;
        for(int j=0; j<l; j++){
          a[j]= Integer.parseInt(s[j]);
        }
        checkmax(a, 0, l-1, l);
        System.out.println(""+result);
      }
    }
}
