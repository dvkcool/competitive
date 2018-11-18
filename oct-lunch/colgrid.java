import java.io.*;
import java.util.*;

public class colgrid{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int rt =0;
        String s[] = br.readLine().trim().split(" ");
        int x = Integer.parseInt(s[0]);
        int y = Integer.parseInt(s[1]);
        String t[] = new String[x];
        for(int j=0; j<x; j++){
          t[j] = br.readLine().trim();
        }
        for(int j=0; j<x; j++){
          for(int k=0; k<y; k++){
            if(t[j].charAt(k)=='#'){
              if(k<2 && k!=0){
                System.out.println("NO");
                rt =1;
                break;
              }
              if((y-k)<3 && (y-k)!=1){
                System.out.println("NO");
                rt =1;
                break;
              }
              if(j<2 && j!=0){
                System.out.println("NO");
                rt =1;
                break;
              }
              if((x-j)<3 && (x-j)!=1){
                System.out.println("NO");
                rt =1;
                break;
              }
              //Go right
              for(int e= k+2; e<(k+3) && e<y; e++){
                if(t[j].charAt(e)=='#'){
                  System.out.println("NO");
                  rt =1;
                  break;
                }
              }
              //Go left
              for(int e= k-2; e>(k-3) && e>=0; e--){
                if(t[j].charAt(e)=='#'){
                  System.out.println("NO");
                  rt =1;
                  break;
                }
              }
              //Go top
              for(int e= j-2; e>(j-3) && e>=0; e--){
                if(t[e].charAt(k)=='#'){
                  System.out.println("NO");
                  rt =1;
                  break;
                }
              }
              //Go below
              for(int e= j+2; e<(j+3) && e<x; e++){
                if(t[e].charAt(k)=='#'){
                  System.out.println("NO");
                  rt =1;
                  break;
                }
              }
            }
          }
          if(rt==1){
            break;
          }
        }
        if(rt==0)
        System.out.println("YES");
      }
    }
}
