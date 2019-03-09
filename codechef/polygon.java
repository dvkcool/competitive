import java.io.*;
import java.util.*;

public class Polygon{
  public static int counter = 0;
  public static void checkeach(double data[], int r){
    double sum = 0;
    for(int i=0; i<r; i++){
      sum+=data[i];
    }
    int c = 0;
    for(int i=0; i<r; i++){
      if(data[i] < (sum/2)){
        c++;
      }
    }
    if(c==r){
      counter = r;
      System.out.println(""+r);
    }

  }
  public static void combination(int arr[], int n, int r, int index,
                            double data[], int i)
{
    if (index == r)
    {
        checkeach(data, r);
    return;
    }
    if (i >= n)
    return;
    data[index] = arr[i];
    combination(arr, n, r, index+1, data, i+1);
    combination(arr, n, r, index, data, i+1);
}

static void checkPolygon(int arr[], int n, int r)
{
    double data[]=new double[r];
    combination(arr, n, r, 0, data, 0);
}
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int len = Integer.parseInt(br.readLine().trim());
      int fullArr[] = new int[len];
      String arr[] = br.readLine().trim().split(" ");
      for(int i=0; i<len; i++){
        fullArr[i] = Integer.parseInt(arr[i]);
      }
      for(int i=len; i>2; i--){
        if(counter!=0){
          return;
        }
        checkPolygon(fullArr, len, i);
      }
      if(counter==0){
        System.out.println("0");
      }

   }
}
