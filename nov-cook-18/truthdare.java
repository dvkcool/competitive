import java.io.*;
import java.util.*;

public class truthdare{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        HashMap<Integer, Integer> truth = new HashMap<>();
        HashMap<Integer, Integer> dare = new HashMap<>();
        int y =0;
        int tr = Integer.parseInt(br.readLine().trim());
        String s[] = br.readLine().trim().split(" ");
        for(int j=0; j<tr; j++){
          truth.put(Integer.parseInt(s[j]), 1);
        }
        int dr = Integer.parseInt(br.readLine().trim());
        String st[] = br.readLine().trim().split(" ");
        for(int j=0; j<dr; j++){
          dare.put(Integer.parseInt(st[j]), 1);
        }
        int str = Integer.parseInt(br.readLine().trim());
        String tt[] = br.readLine().trim().split(" ");
        for(int j=0; j<str; j++){
          int r = Integer.parseInt(tt[j]);
          if(!(truth.containsKey(r))){
            System.out.println("no");
            y = 1;
            break;
          }
        }
        int dtr = Integer.parseInt(br.readLine().trim());
        String dtt[] = br.readLine().trim().split(" ");
        if(y==0)
        for(int j=0; j<dtr; j++){
          int r = Integer.parseInt(dtt[j]);
          if(!(dare.containsKey(r))){
            System.out.println("no");
            y = 1;
            break;
          }
        }

        if(y==0){
          System.out.println("yes");
        }


      }
    }
}
