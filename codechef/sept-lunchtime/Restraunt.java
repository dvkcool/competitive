
import java.io.*;
import java.util.*;

public class Restraunt{
  static class interval{
    int opentime;
    int closetime;

    interval(int i, int j){
      opentime = i;
      closetime = j;
    }
  }
  static int partition(interval arr[], int low, int high){
    interval pivot = arr[high];
    int i = (low-1);
    for (int j=low; j<high; j++)
    {
        if (arr[j].opentime <= pivot.opentime)
        {
            i++;
            interval temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    interval temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}
static void sort(interval arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        sort(arr, low, pi-1);
        sort(arr, pi+1, high);
    }
}
/*
static int search(interval arr[], int x){
  for(int i=0; i<arr.length; i++){
    if(x<arr[i].closetime){
      if(x>= arr[i].opentime){
        return 0;
      }
      else{
          return arr[i].opentime-x;
      }
    }
  }
  return -1;
}
*/
static int search(interval arr[], int l, int r, int x)
    {
        if (r>=l)
        {
            int mid = l + (r - l)/2;
            if(x<arr[mid].closetime){
              if(mid!=0){
                if(x>=arr[mid-1].closetime){
                  if(x>= arr[mid].opentime){
                    return 0;
                  }
                  else{
                      return arr[mid].opentime-x;
                  }
                }
              }
              else{
                if(x>= arr[mid].opentime){
                  return 0;
                }
                else{
                    return arr[mid].opentime-x;
                }
              }

            }
            if (arr[mid].closetime > x){
              return search(arr, l, mid-1, x);
            }
            else{
              return search(arr, mid+1, r, x);
            }

        }


        return -1;
    }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        interval ret[] = new interval[n];
        for(int j=0; j<n; j++){
          String t[] = br.readLine().trim().split(" ");
          ret[j] = new interval(Integer.parseInt(t[0]), Integer.parseInt(t[1]));
        }
        sort(ret, 0, n-1);
        for(int j=0; j<m; j++){
          System.out.println(""+search(ret, 0, n-1, Integer.parseInt(br.readLine().trim())));
        }
      }
    }
}
