import java.io.*;
import java.util.*;

public class Ballc{
  public static void printMax(int a, int b, int c, int d, int e){
    if(c==a || c==b){
      System.out.println("! "+d);
    }
    else if(d==a || d==b){
      System.out.println("! "+c);
    }
    else{
      System.out.println("! "+e);
    }
  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int n = Integer.parseInt(br.readLine().trim());
        int a[] = {1, 2, 3, 4, 5};
        int e[] = new int[3];
        int de = 0;
        int j=5;
        int brt = 0;
        while(true){
          System.out.print("? "+a[0]+" "+a[1]+" "+a[2]+" "+a[3]+" "+a[4]+"\n");
          String s[] = br.readLine().trim().split(" ");
          int b[] = new int[2];
          b[0] = Integer.parseInt(s[0]);
          b[1] = Integer.parseInt(s[1]);
          int k=0;
          int c[] = new int[3];
          if(de==0){
            e[0] = b[0];
            e[1] = b[1];
            de =1;
          }
          else if(de==1){
            if(b[0]!=e[0] && b[0]!=e[1]){
              e[2] = b[0];
              de =2;
            }
            else if(b[1]!=e[0] && b[1]!=e[1]){
              e[2] = b[1];
              de =2;
            }
          }

          // de part over


          for(int p=0; p<5; p++){
            if(a[p]==b[0] || a[p]==b[1]){
              continue;
            }
            c[k] = a[p];
            k++;
          }
          a[0] = c[0];
          a[1] = c[1];
          a[2] = c[2];
          if(j>=n){
            break;
          }


          if(j<=(n-2)){
            a[3] = j+1;
            a[4] = j+2;
            j = j+2;
          }
          else if(j==(n-1)){
              a[3] = j+1;
              a[4] = e[0];
              j = n;
          }


        }

        String y[] = new String[3];

        System.out.println("? "+e[0]+" "+e[1]+" "+e[2]+" "+a[0]+" "+a[1]);
        y[0] = br.readLine().trim();
        System.out.println("? "+e[0]+" "+e[1]+" "+e[2]+" "+a[2]+" "+a[1]);
        y[1] = br.readLine().trim();
        System.out.println("? "+e[0]+" "+e[1]+" "+e[2]+" "+a[0]+" "+a[2]);
        y[2] = br.readLine().trim();

        if(y[0].equals(y[1])){
          String se[] = y[2].split(" ");
          int pet1 = Integer.parseInt(se[0]);
          int pet2 = Integer.parseInt(se[1]);
          printMax(pet1, pet2, a[0], a[2], a[1]);
        }
        else if(y[1].equals(y[2])){
          String se[] = y[0].split(" ");
          int pet1 = Integer.parseInt(se[0]);
          int pet2 = Integer.parseInt(se[1]);
          printMax(pet1, pet2, a[0], a[1], a[2]);
        }
        else if(y[0].equals(y[2])){
          String se[] = y[1].split(" ");
          int pet1 = Integer.parseInt(se[0]);
          int pet2 = Integer.parseInt(se[1]);
          printMax(pet1, pet2, a[1], a[2], a[0]);
        }
      }
    }
}
