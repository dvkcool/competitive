import java.io.*;
import java.util.*;

public class DayOfWeek{
  static int day(String s){
    char c = s.charAt(0);
    if(c=='m'){
      return 1;
    }
    else if(c=='t'){
      if(s.charAt(1)=='u'){
        return 2;
      }
      else{
        return 4;
      }
    }
    else if(c=='w'){
      return 3;
    }
    else if(c=='f'){
      return 5;
    }
    else{
      if(s.charAt(1)=='a'){
        return 6;
      }
      else{
        return 7;
      }
    }
  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        int d1 = day(s[0]);
        int d2 = day(s[1]);
        int l = Integer.parseInt(s[2]);
        int r = Integer.parseInt(s[3]);
        int d = 0;
        if(d1>d2){
          d = (7-d1+1)+d2;
        }
        else{
          d = d2-d1 +1;
        }
        int e = d;
        int c = 0;
        int m = d;
        int k = 0;
        if(e<=r){
          while(e<=r){
            if(e>=l && e<=r){
              m = e;
              c++;
              if(c>1){
                k =1;
                System.out.println("many");
                break;
              }
            }
            e += 7;
          }
          if(c==1){
            System.out.println(""+m);
          }
          else if(k!=1){
            System.out.println("impossible");
          }
        }
        else{
          System.out.println("impossible");
        }

      }
    }
}
