import java.io.*;
import java.util.*;

public class Main{
  public static void transformBacteria(char arr[][], int m, int n, int ji, int jj, int ki, int kj, int g){
    if(g==0){
      for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
          System.out.print(""+arr[i][j]);
        }
        System.out.println("");
      }
      return;
    }
    char arrNew[][] = new char[m][n];
    //modify cells
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
          int count =0;
          //above row
          if(i>0){
            if(j>0){
              if(arr[i-1][j-1] == '1')
              count++;
            }
            if(arr[i-1][j] == '1'){
              count++;
            }
            if(j<(n-1)){
              if(arr[i-1][j+1] == '1'){
                count++;
              }

            }
          }
          //same row
          if(j>0){
            if(arr[i][j-1] == '1'){
              count++;
            }
          }
          if(j<(n-1)){
            if(arr[i][j+1] == '1')
            count++;
          }
          //below row
          if(i<(m-1)){
            if(j>0){
              if(arr[i+1][j-1] == '1')
              count++;
            }
            if(arr[i+1][j] == '1'){
              count++;
            }
            if(j<(n-1)){
              if(arr[i+1][j+1] == '1')
              count++;
            }
          }

          if(arr[i][j] == '0'){
            if(count>= ki && count<= kj){
              arrNew[i][j] = '1';
            }
            else{
              arrNew[i][j] = '0';
            }

          }
          else if(arr[i][j] == '1'){
            if(count>= ji && count<= jj){
              arrNew[i][j] = '1';
            }
            else{
              arrNew[i][j] = '0';
            }

          }




      }
    }
    transformBacteria(arrNew, m, n, ji, jj, ki, kj, --g);
  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String dimension[] = br.readLine().trim().split(" ");
        int m = Integer.parseInt(dimension[0]);
        int n = Integer.parseInt(dimension[1]);
        char charArr[][] = new char[m][n];
        for(int j = 0; j<m; j++){
          String s = br.readLine().trim();
          for(int k=0; k<n; k++){
            charArr[j][k] = s.charAt(k);
          }
        }
        String s[] = br.readLine().trim().split(" ");
        int ji = Integer.parseInt(s[0]);
        int jj = Integer.parseInt(s[1]);
        String r[]  = br.readLine().trim().split(" ");
        int ki = Integer.parseInt(r[0]);
        int kj = Integer.parseInt(r[1]);
        int g = Integer.parseInt(br.readLine().trim());
        transformBacteria(charArr, m, n, ji, jj, ki, kj, g);
      }

   }
}
