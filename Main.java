import java.io.*;
import java.util.*;

public class Main{
  public class Student{
    public int level;
    public int solved;
    public void setval(int a, int b){
      this.level = a;
      this.solved = b;
    }
  }
static  void merge(Student arr[], int l, int m, int r)
{
    // Find sizes of two subarrays to be merged
    int n1 = m - l + 1;
    int n2 = r - m;

    /* Create temp arrays */
    Student L[] = new Student [n1];
    Student R[] = new Student [n2];

    /*Copy data to temp arrays*/
    for (int i=0; i<n1; ++i)
        L[i] = arr[l + i];
    for (int j=0; j<n2; ++j)
        R[j] = arr[m + 1+ j];


    /* Merge the temp arrays */

    // Initial indexes of first and second subarrays
    int i = 0, j = 0;

    // Initial index of merged subarry array
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].level <= R[j].level)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy remaining elements of L[] if any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy remaining elements of R[] if any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Main function that sorts arr[l..r] using
// merge()
static void sort(Student arr[], int l, int r)
{
    if (l < r)
    {
        // Find the middle point
        int m = (l+r)/2;

        // Sort first and second halves
        sort(arr, l, m);
        sort(arr , m+1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String s[] = br.readLine().trim().split(" ");

      int cases = Integer.parseInt(s[0]);
      int len = Integer.parseInt(s[1]);
      for(int i=0; i<cases; i++){
        String levels[] = br.readLine().trim().split(" ");
        String solvedNumber[] =  br.readLine().trim().split(" ");
        Student superman[] = new Student[len];
        for(int j=0; j<len; j++){
          superman[j].setval(Integer.parseInt(levels[j]), Integer.parseInt(solvedNumber[j]));
        }
        sort(superman, 0, len-1);
        int k = 1;
        for(int j=1; j<len; j++){
          if(superman[j].solved < superman[j-1].solved){
            k++;
          }
        }
        System.out.println(""+k);
      }

   }
}
