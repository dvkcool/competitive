import java.io.*;
import java.util.*;

public class choc{
  static int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low-1); // index of smaller element
    for (int j=low; j<high; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;

            // swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // swap arr[i+1] and arr[high] (or pivot)
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}


/* The main function that implements QuickSort()
  arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
static void sort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[pi] is
          now at right place */
        int pi = partition(arr, low, high);

        // Recursively sort elements before
        // partition and after partition
        sort(arr, low, pi-1);
        sort(arr, pi+1, high);
    }
}


  static int piece(int a[][], int m, int n, int l){
    int d = n-m;
    if(d>=l){
      return 0;
    }
    if(m>=l){
      return 0;
    }
    return a[d][m];
  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String s[] = br.readLine().trim().split(" ");
      int n = Integer.parseInt(s[0]);
      int k = Integer.parseInt(s[1]);
      int a[][] = new int[n][n];
      int q[] = new int[k];
      String sa[] = br.readLine().trim().split(" ");
      String sq[] = br.readLine().trim().split(" ");
      for(int i=0; i<n; i++){
        a[0][i] = Integer.parseInt(sa[i]);
      }
      for(int i=0; i<k; i++){
        q[i] = Integer.parseInt(sq[i]);
      }
      for(int i=1; i<n; i++){
        for(int j=0; j<(n-i); j++){
          a[i][j] = a[i-1][j] + a[0][i+j];
        }
      }
      /*
      System.out.println("Matrix");
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          System.out.print(" "+a[i][j]);
        }
        System.out.println("");
      }
      */

      for(int i=0; i<k; i++){
        sort(q, 0, i);
        int st = 0;
        int max = 0;
        for(int j=0; j<=i; j++){
          int kr = piece(a, st, q[j]-1, n);
          st = q[j];
          if(kr>max){
            max = kr;
          }
        }
        int kr = piece(a, st, n-1, n);
        if(kr>max){
          max = kr;
        }
        System.out.println(""+max);
      }



    }
}
