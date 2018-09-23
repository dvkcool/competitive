import java.io.*;
import java.util.*;

public class Main{
  public static void NoOfUpDown(int noUp, int sameUp, int noDown, int sameDown){
    int a[] = new int[noUp];
    int b[] = new int[noDown];
    for(int i =0; i<noUp; i++){
      a[i] = combin(noUp, i+1, sameUp);
    }
    for(int i =0; i<noDown; i++){
      b[i] = combin(noDown, i+1, sameDown);
    }
    int result = 0;
    for(int i=0; i<noUp; i++){
      for(int j=0; j<noDown; j++){
        result = result + a[i]*b[j];
      }
    }
    System.out.println(""+result);
  }
  public static int combin(int full, int select, int same){
    return factorial(full)/factorial(full-select)/factorial(select)/factorial(same);
  }
  public static int factorial(int a){
    if(a<=0){
      return 1;
    }
    int result = 1;
    for(int i=2; i<=a; i++){
      result = result*i;
    }
    return result;
  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int len = Integer.parseInt(br.readLine().trim());
      int fullArr[] = new int[len];
      String arr[] = br.readLine().trim().split(",");
      int noUp = 0;
      int sameUp = 0;
      int sameDown = 0;
      int noDown = 0;
      int counter = 0;
      int max;
      int maxIndex = 0;
      for(int i=0; i<len; i++){
        fullArr[i] = Integer.parseInt(arr[i]);
        if(i==0){
          max = fullArr[i];
        }
        if(fullArr[i]>max){
          max=fullArr[i];
          maxIndex=i;
        }
      }
      int c = 0;
      int d = 0;
      //Checking for ascending/descending order
      for(int i=1; i<len; i++){
        if(fullArr[i]>=fullArr[i-1]){
          c++;
        }
        if(fullArr[i]<=fullArr[i-1]){
          d++;
        }
      }
      if(c==len-1 || d==len-1){
        System.out.println("0");
        return;
      }



      NoOfUpDown(noUp, sameUp, noDown, sameDown);
   }
}
