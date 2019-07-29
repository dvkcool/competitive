import java.io.*;
import java.util.*;

public class triangle{
  public static void main(String args[] ) throws Exception {
    int r = 0;
      for(int i=1; i<=1000; i++){
        for(int j=1; j<=1000; j++){
          for(int k = 1; k<=1000; k++){

            if((i+j+k)>1000){
              continue;
            }
            if(Math.pow(i, 2)+ Math.pow(j, 2) == (Math.pow(k, 2) -1)){
              r++;
            }
          }
        }
      }
      System.out.println(""+r);
    }
}
