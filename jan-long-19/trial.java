import java.io.*;
import java.util.*;

public class trial{
  public static void main(String args[] ) throws Exception {
        int n =50;
        int max =0;
        for(int i=100; i>0; i--){
          for(int j=100; j>0; j--){
            for(int k=100; k>0; k--){
              int l = (((n%i)%j)%k)%n;
              if(l==0){
                continue;
              }
              if(l==24){
                max++;
              }
              //System.out.println("n: "+n+" i: "+i+" j: "+j+" k: "+k+" ans: "+l);
            }
          }
        }
        System.out.println("max: "+max);
    }
}
