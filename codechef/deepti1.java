import java.io.*;
import java.util.*;

public class deepti1{
  public static void main(String args[] ) throws Exception {
    int i=0;
    int j= 1;
    while(j<5){
      i = i + j;
      int temp = i;
      int k = j;
      while(k>0){
        System.out.print(" "+i);
        i--;
        k--;
      }
      j++;
      i = temp;
      System.out.println("");
    }
}
}
