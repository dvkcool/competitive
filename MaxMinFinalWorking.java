import java.io.*;
import java.util.*;

public class Main{
   public static void MaximumSeq(int arr[],int n){
       int upSeq[] = new int[n];
       int downSeq[] = new int[n];
       int i,j,max = 0;
       int maxIndex = 0;
        for ( i = 0; i < n; i++ ){
          upSeq[i] = 1;
          downSeq[i] = 1;
        }
        for ( i = 1; i < n; i++ ){
          for ( j = 0; j < i; j++ ){
            if ( arr[i] > arr[j] && upSeq[i] < upSeq[j] + 1){
              upSeq[i] = upSeq[j] + 1;
            }
          }
        }
        for ( i = n-2; i >=0; i-- ){
          for ( j = n-1; j > i; j-- ){
            if ( arr[i] > arr[j] && downSeq[i] < downSeq[j] + 1){
              downSeq[i] = downSeq[j] + 1;
            }
          }
        }
        //Maximum Sum of up and down sequence
        for ( i = 0; i < n; i++ ){
          int product = upSeq[i] * downSeq[i];
          if ( max <= product ){
            max = product;
            maxIndex = i;
          }
        }
        NoOfUpDown(upSeq[maxIndex] -1, downSeq[maxIndex] -1);

  }
  public static void NoOfUpDown(int noUp, int noDown){
    int a[] = new int[noUp];
    int b[] = new int[noDown];
    for(int i =0; i<noUp; i++){
      a[i] = combin(noUp, i+1);
    }
    for(int i =0; i<noDown; i++){
      b[i] = combin(noDown, i+1);
    }
    int result = 0;
    for(int i=0; i<noUp; i++){
      for(int j=0; j<noDown; j++){
        result = result + a[i]*b[j];
      }
    }
    System.out.println(""+result);
  }
  public static int combin(int full, int select){
    return factorial(full)/factorial(full-select)/factorial(select);
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
      for(int i=0; i<len; i++){
        fullArr[i] = Integer.parseInt(arr[i]);
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
      MaximumSeq(fullArr, len);
   }
}
