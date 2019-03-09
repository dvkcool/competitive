import java.io.*;
import java.util.*;

public class third{
  public static int findInterest(String s[][], int count[], int a, int b, int d, int prev){
    int match = 0;
    if((d%2 != 0) && (a==prev || b==prev)){
      return Integer.MIN_VALUE;
    }
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
      String s[][] = new String[n][200];
      int count[] = new int[n];
      int don[] = new int[n];
      String id[] = new String[n];
      int d = 0;
      int prev = 0;
      //Taking max c = 10000
      for(int i=0; i<n; i++){
        String st[] = br.readLine().trim().split(" ");
        if(st[0].charAt(0)=='H'){
          count[c] = Integer.parseInt(st[1]);
          id[c] = ""+i;
          for(int j=0; j<count[c]; j++){
            s[c][j] = st[j+2];
          }
          c++;
          if(c>=10000){
            break;
          }
        }
        if(st[0].charAt(0)=='V'){
          if(d%2!=0){
            int mprev = count[prev];
            count[prev] += Integer.parseInt(st[1]);
            id[prev] = id[prev]+" "+ i;
            for(int j=mprev; j<count[prev]; j++){
              s[prev][j] = st[j+2-mprev];
            }
          }
          else{
            count[c] = Integer.parseInt(st[1]);
            id[c] = ""+i;
            for(int j=0; j<count[c]; j++){
              s[c][j] = st[j+2];
            }
            prev = c;
            c++;
            if(c>=10000){
              break;
            }
          }
          d++;
        }
      }
      if(d%2!=0){
        c--;
      }
      System.out.println(""+c);
      if(c!=0){
        don[0] = 1;
        System.out.println(id[0]);
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
            int interest = findInterest(s, count, k, j, d, prev);
            if(max < interest){
              max = interest;
              index = j;
            }
          }
          if(t==0){
            break;
          }
          if(index != prev && d%2!=0)
          System.out.println(id[index]);
          k = index;
        }
      }

    }
}
