import java.io.*;
import java.util.*;

public class Main{
  static String Line(BufferedReader br){
    String s = "";
    try{
      s = br.readLine();
    }
    catch(IOException e){

    }
    return s;
  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(Line(br).trim());
      for(int i=0; i<cases; i++){
        String s[] = Line(br).split(" ");
        int n = Integer.parseInt(s[0]);
        int q = Integer.parseInt(s[1]);
        int a[] = new int[n];
        int b[] = new int[n];
        String sa[] = Line(br).split(" ");
        String sb[] = Line(br).split(" ");
        int result =0;
        for(int j=0; j<n; j++){
          a[j] = Integer.parseInt(sa[j]);
          b[j] = Integer.parseInt(sb[j]);
          if(a[j]==b[j]){
            result++;
          }
          a[j] = result;
        }
        for(int j=0; j<q; j++){
          String nq[] = Line(br).split(" ");
          int l = Integer.parseInt(nq[0]);
          int r = Integer.parseInt(nq[1]);
          int c = Integer.parseInt(nq[2]);
          l = l ^ result;
          r = r ^ result;
          c = c ^ result;
          result = 0;
          if(l<1){
            l=1;
          }
          for(int k = l-1; k<r && k<n; k++ ){
            if(b[k]==c){
              result++;
            }
          }
          if(l>1){
            result = result + a[l-2];
          }
          if(r < n && r>0){
            result = result + a[n-1] - a[r-1];
          }
          System.out.println(""+result);
        }


      }
    }
}
