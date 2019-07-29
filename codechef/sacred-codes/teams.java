import java.io.*;
import java.util.*;

public class teams{
  static class FastReader
{
  BufferedReader br;
  StringTokenizer st;

  public FastReader()
  {
      br = new BufferedReader(new
               InputStreamReader(System.in));
  }

  String next()
  {
      while (st == null || !st.hasMoreElements())
      {
          try
          {
              st = new StringTokenizer(br.readLine());
          }
          catch (IOException  e)
          {
              e.printStackTrace();
          }
      }
      return st.nextToken();
  }

  int nextInt()
  {
      return Integer.parseInt(next());
  }

  long nextLong()
  {
      return Long.parseLong(next());
  }

  double nextDouble()
  {
      return Double.parseDouble(next());
  }

  String nextLine()
  {
      String str = "";
      try
      {
          str = br.readLine();
      }
      catch (IOException e)
      {
          e.printStackTrace();
      }
      return str;
  }
}
  static class tm{
    String s1;
    String ts[];
    int dp;
    int c;
    tm(){
      c=0;
      s1="";
      dp =0;
      ts = new String[2];
    }
  }
  public static void main(String args[] ) throws Exception {
      //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      FastReader s=new FastReader();
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = s.nextInt();
      tm tms[] = new tm[100000];
      for(int i=0; i<100000; i++){
        tms[i] = new tm();
      }
      for(int i=0; i<cases; i++){
        int n = s.nextInt();
        int q = s.nextInt();
        for(int j=0; j<n; j++){
          for(int k=0; k<3; k++){
            String te[] = s.nextLine().split(" ");
            int m = Integer.parseInt(te[0]);
            m--;
            if(te[2].charAt(0)=='Y'){
              tms[m].s1 = te[1];
            }
            else{
              tms[m].ts[tms[m].c] = te[1];
              tms[m].c = (tms[m].c + 1)%2;
            }
            tms[m].dp = 0;
          }
        }
        for(int j=0; j<q; j++){
          int p = s.nextInt();
          int k = s.nextInt();
          if(tms[p-1].dp==1 && k!=1){
            bw.append(tms[p-1].ts[k-2]+"\n");
            continue;
          }
          if(k==1){
            bw.append(tms[p-1].s1+"\n");
            continue;
          }
          else if(k==2){
            if((tms[p-1].ts[0].compareTo(tms[p-1].ts[1]))<0){
              bw.append(tms[p-1].ts[0]+"\n");
              tms[p-1].dp = 1;
              continue;
            }
            else{
              bw.append(tms[p-1].ts[1]+"\n");
              String tl = tms[p-1].ts[1];
              tms[p-1].ts[1] = tms[p-1].ts[0];
              tms[p-1].ts[0] = tl;
              tms[p-1].dp = 1;
              continue;
            }
          }
          else{
            if((tms[p-1].ts[0].compareTo(tms[p-1].ts[1]))<0){
              bw.append(tms[p-1].ts[1]+"\n");
              tms[p-1].dp = 1;
              continue;
            }
            else{
              bw.append(tms[p-1].ts[0]+"\n");
              String tl = tms[p-1].ts[1];
              tms[p-1].ts[1] = tms[p-1].ts[0];
              tms[p-1].ts[0] = tl;
              tms[p-1].dp = 1;
              continue;
            }
          }
        }
      }
      bw.flush();
      bw.close();
    }
}
