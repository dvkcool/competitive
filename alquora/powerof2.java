import java.io.*;
import java.util.*;

public class Main{
  static int c = 0;
  public static void main(String args[] ) throws Exception {
      Scanner sc = new Scanner(System.in);
      int cases = sc.nextInt();
      for(int i=0; i<cases; i++){
        c = 0;
        int num = sc.nextInt();
        String s = ""+num;
        permutationStr(s, 0, s.length()-1);
        if(c==0){
          System.out.println("-1");
        }
      }
    }
    public static boolean isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;

        while (n != 1)
        {
            if (n % 2 != 0)
                return false;
            n = n / 2;
        }
        return true;
    }
    public static void checkstr(String s){
      int i = Integer.parseInt(s);
      if(isPowerOfTwo(i)){
        System.out.println(s);
        c++;
      }
    }
    private static void permutationStr(String s, int i, int j){
        if(c!=0){
          return;
        }
        if (i == j){
          checkstr(s);
        }
        else{
            for (int k = i; k <= j; k++)
            {
                s  = swap(s,i,k);
                permutationStr(s, i+1, j);
                s = swap(s,i,k);
            }
        }
    }
    public static String swap(String a, int i, int j)
    {
        char temp;
        char[] charArray = a.toCharArray();
        temp = charArray[i] ;
        charArray[i] = charArray[j];
        charArray[j] = temp;
        return String.valueOf(charArray);
    }
}
