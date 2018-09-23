import java.io.*;
import java.util.*;

public class Solution {
    static int compareLex(String a, String b, int i, int j, int l1, int l2){
      int c = 0;
      while(c==0){
        if(a.charAt(i)<b.charAt(j)){
            return -1;
        }
        else if(a.charAt(i)>b.charAt(j)){
            return 1;
        }
        else{
            if(i<(l1-1)){
                if(j<(l2-1)){
                    i++;
                    j++;
                }
                else{
                  return -1;
                }
            }
            return 1;
        }
      }
      return 1;

    }
    // Complete the morganAndString function below.
    static void morganAndString(String a, String b, int l1, int l2) {
        int i = 0;
        int j = 0;
        while(i<l1 && j<l2){
            int k = compareLex(a, b, i, j, l1, l2);
            if(k<0){
                System.out.print(""+a.charAt(i));
                i++;
            }
            else{
                System.out.print(""+b.charAt(j));
                j++;
            }
        }
        while(i<l1){
            System.out.print(""+a.charAt(i));
                i++;
        }
        while(j<l2){
            System.out.print(""+b.charAt(j));
                j++;
        }
        System.out.println("");
    }



    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        String a, b;
        for(int i=0; i<t; i++){
            if((a = br.readLine()) == null){
              a="";
            }
            if((b = br.readLine()) == null){
              b="";
            }
            int l1 = a.length();
            int l2 = b.length();
            morganAndString(a, b, l1, l2);
        }
    }
}
