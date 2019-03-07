import java.io.*;
import java.util.*;

public class first{
  public static int findInterest(String s[][], int count[], int a, int b){
    int match = 0;
    for(int i=0; i<count[a]; i++){
      for(int j=0; j<count[b]; j++){
        if(s[a][i].equals(s[b][j])){
          match++;
        }
      }
    }
    return Math.min(count[a]-match, Math.min(count[b]-match, match));
  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine().trim());
      int c = 0;
      String s[][] = new String[n][100];
      int count[] = new int[n];
      int don[] = new int[n];
      int id[] = new int[n];
      for(int i=0; i<n; i++){
        String st[] = br.readLine().trim().split(" ");
        if(st[0].charAt(0)=='H'){
          count[c] = Integer.parseInt(st[1]);
          id[c] = i;
          for(int j=0; j<count[c]; j++){
            s[c][j] = st[j+2];
          }
          c++;
        }
      }
      System.out.println(""+c);
      don[0] = 1;
      System.out.println(""+id[0]);
      int k = 0;
      while(true){
        int t = 0;
        don[k] = 1;
        int max = Integer.MIN_VALUE;
        int index = 0;
        for(int j=0; j<c; j++){
          if(don[j]==1){
            continue;
          }
          if(j==k){
            continue;
          }
          t++;
          int interest = findInterest(s, count, k, j);
          if(max < interest){
            max = interest;
            index = j;
          }
        }
        if(t==0){
          break;
        }
        System.out.println(""+id[index]);
        k = index;
      }
    }
}
