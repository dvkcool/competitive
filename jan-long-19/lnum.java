import java.io.*;
import java.util.*;

public class lnum{
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        int n = Integer.parseInt(s[0]);
        int a = Integer.parseInt(s[1]);
        int b = Integer.parseInt(s[2]);
        int bob = 0;
        int al = 0;
        int cm = 0;
        int turn = 0;
        String st[] = br.readLine().trim().split(" ");
        for(int j=0; j<n; j++){
          int m = Integer.parseInt(st[j]);
          if(((m%a)==0) && ((m%b)==0)){
            cm++;
          }
          else if((m%a)==0){
            bob++;
          }
          else if((m%b)==0){
            al++;
          }
        }
        /*
        if((cm%2) !=0){
          if(al>bob){
            System.out.println("ALICE");
          }
          else{
            System.out.println("BOB");
          }
        }
        else{
          if(bob>al){
            System.out.println("BOB");
          }
          else{
            System.out.println("ALICE");
          }
        }
        */

        while(true){
          if(cm==0 && (bob==0 || al==0)){
            break;
          }
          if(turn%2==0){
            if(cm!=0 && (bob!=0 || al==0)){
              cm = 0;
            }
            else if(cm!=0){
              cm--;
            }
            else{
              bob--;
            }
          }
          else{
            if(cm!=0 && (al!=0 || bob==0)){
              cm = 0;
            }
            else if(cm!=0){
              cm--;
            }
            else{
              al--;
            }
          }
          turn++;
        }

        if(bob !=0 ){
          System.out.println("BOB");
        }
        else if(al !=0){
          System.out.println("ALICE");
        }
        else{
          if(turn%2==0){
            System.out.println("ALICE");
          }
          else{
            System.out.println("BOB");
          }
        }

      }
    }
}
