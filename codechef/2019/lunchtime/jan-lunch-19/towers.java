import java.io.*;
import java.util.*;

public class towers{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int l = Integer.parseInt(br.readLine().trim());
        char c[] = br.readLine().trim().toCharArray();
        int r = 0;
        for(int j=0; j<l; j++){
          if(c[j]=='1'){
            j++;
            continue;
          }
          else if(j==0){
            if(l>1){
              if(c[j+1]!='1'){
                  r++;
                  c[j] = '1';
                  continue;
              }
            }
            else{
              r++;
              continue;
            }
          }
          else if(j==(l-1)){
            if(l>1 && c[j-1]!='1'){
              r++;
              c[j] = '1';
              continue;
            }
          }
          else if(c[j-1]!='1' && c[j+1]!='1'){
                  r++;
                  c[j] = '1';
                  continue;
          }
        }

        bw.append(r+"\n");
      }
      bw.flush();
      bw.close();
    }
}
