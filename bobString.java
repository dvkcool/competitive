import java.io.*;
import java.util.*;
public class Main
{
public static void main(String args[] ) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int cases = Integer.parseInt(br.readLine().trim());

    for(int i=0; i<cases; i++){
        String a = br.readLine().trim();
        String b = br.readLine().trim();
        String s = "bob";
        int counter = 0;
        for(int j = 0; j<3; j++){
         if(j==1){
           s="bbo";
         }
         else if(j==2){
           s="obb";
         }
         for(int k=0; k<3; k++){
         	if(a.charAt(k) == s.charAt(k) || b.charAt(k) == s.charAt(k)){
           		if(k==2){
           			counter=1;
                break;
           		}
         	}
         	else{
         		break;
         	}
         }
        }
        if(counter == 1){
        	System.out.println("yes");
        }
        else{
        	System.out.println("no");
        }
    }
   }
   }
