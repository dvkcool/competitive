import java.io.*;
import java.util.*;

public class periodic{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int l = Integer.parseInt(br.readLine().trim());
        String s[] = br.readLine().trim().split(" ");
        int a[] = new int[l];
        int t[] = new int[l];
        int lt = 0;
        a[0]= Integer.parseInt(s[0]);
        int prev = -2;
        if(a[0]!=-1){
          prev=a[0];
          t[0]=a[0];
        }
        if(a[0]==-1){
          lt++;
        }
        int b =0;

        for(int j=1; j<l; j++){
          a[j]= Integer.parseInt(s[j]);
          if(a[j]==-1){
            lt++;
          }
          if(prev==-2 && a[j]==1){
            System.out.println("inf");
          }
          if(prev!=-2){
            if(a[j]!=-1){
              if(a[j]<prev){
                if(a[j]==1){
                  if(t[j-1]==-1 || t[j-1]==0){
                    System.out.println("inf");
                    b=1;
                    break;
                  }
                  System.out.println(""+t[j-1]);
                }
                else{
                  if((j-a[j]+1)>=0){
                    if(a[j-a[j]+1] == -1 || a[j-a[j]+1] ==1){
                      if(t[j-a[j]]==0){
                        System.out.println("inf");
                        b=1;
                        break;
                      }
                      System.out.println(""+t[j-a[j]]);
                    }
                    else{
                      System.out.println("inf");
                      b=1;
                      break;
                    }
                  }
                  else{
                    System.out.println("inf");
                    b=1;
                    break;
                  }
                }
              }
              else if(a[j]!=(prev+1)){
                System.out.println("impossible");
                b = 1;
                break;
              }

            }
            if(prev!=-2){
              prev++;
              t[j] = prev;
            }
          }
          else if(prev==-2 && a[j]!=-1){
            prev = a[j];
            t[j] = a[j];
          }
          else if(prev!=-2){
            prev++;
            t[j] = prev;
          }
        }
        if(b==1){
          continue;
        }
        if(lt==l){
          System.out.println("inf");
        }

      }
    }
}
