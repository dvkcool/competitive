import java.io.*;
import java.util.*;

public class xortr{
  public static void main(String args[] ) throws Exception {
      for(int i=1; i<100; i++){
        for(int j=1; j<100; j++){
          if(i==j){
            continue;
          }
          for(int k=1; k<100; k++){
            if(i==k || j==k){
              continue;
            }
            System.out.println(" case"+i+": "+i+" "+j+" " +k +"xor: "+(i^j^k));
          }
          //System.out.println(" case"+i+": "+i+" "+(i+1)+" " +(i+2) +"xor: "+(i^(i+1)^(i+2)));
        }
        //System.out.println(" case"+i+": "+i+" "+(i+1)+" " +(i+2) +"xor: "+(i^(i+1)^(i+2)));
      }
    }
}
