import java.io.*;
import java.util.*;
class mlis {
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
static int max;
static int maxt[];
/*
private static int ceilIndex(long input[], int T[], int end, long s){
    int start = 0;
    int middle;
    int len = end;
    while(start <= end){
        middle = (start + end)/2;
        if(middle < len && input[T[middle]] < s && s <= input[T[middle+1]]){
            return middle+1;
        }else if(input[T[middle]] < s){
            start = middle+1;
        }else{
            end = middle-1;
        }
    }
    return -1;
}

public static void lisModified(long input[]){
    int T[] = new int[input.length];
    int R[] = new int[input.length];
    for(int i=0; i < R.length ; i++) {
        R[i] = -1;
    }
    T[0] = 0;
    int len = 0;
    for(int i=1; i < input.length; i++){
        if(((input[T[0]] & input[i]) ==input[i])){ //if input[i] is less than 0th value of T then replace it there.
            T[0] = i;
        }else if((input[T[len]]&input[i])==input[T[len]]){ //if input[i] is greater than last value of T then append it in T
            len++;
            T[len] = i;
            R[T[len]] = T[len-1];
        }else{ //do a binary search to find ceiling of input[i] and put it there.
            int index = ceilIndex(input, T, len,input[i]);
            T[index] = i;
            R[T[index]] = T[index-1];
        }
    }

    //this prints increasing subsequence in reverse order.
    maxt = new long[len+1];
    int yt = len;
    int index = T[len];
    while(index != -1) {
        maxt[yt] = input[index];
        index = R[index];
        yt--;
    }
    max =  len+1;
}
*/
static void lisModified(long arr[],int n)
    {

          int lis[] = new int[n];
          int i,j = 0;
          max = 0;
          ArrayList<Set<Integer> > aList = new ArrayList<Set<Integer> >();;

           for ( i = 0; i < n; i++ ){
             lis[i] = 1;
             Set<Integer> ty = new HashSet<Integer>();
             ty.add(i);
             aList.add(ty);
           }

           for ( i = 1; i < n; i++ )
              for ( j = 0; j < i; j++ )
                         if ( ((arr[i] > arr[j]) && ((lis[i] < lis[j] + 1) && (arr[j]&arr[i]) == arr[j]))){
                           lis[i] = lis[j] + 1;
                           aList.get(i).addAll(aList.get(j));
                         }


           int y = 0;
           for ( i = 0; i < n; i++ )
              if ( max < lis[i] ){
                max = lis[i];
                y = i;
              }
            maxt = new int[aList.get(y).size()];
            Iterator<Integer> it = aList.get(y).iterator();
            int yr = aList.get(y).size() -1;
             while(it.hasNext()){
                maxt[yr] = it.next();
                yr--;
             }

  }

    public static void main(String args[] ) throws Exception{
      FastReader s=new FastReader();
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = s.nextInt();
      for(int i=0; i<cases; i++){
        int n = s.nextInt();
        long a[] = new long[n];
        for(int j=0; j<n; j++){
          a[j] = s.nextLong();
        }
        lisModified(a);
        bw.append(max+"\n");
        for(int j= maxt.length - 1; j>=0; j--){
          bw.append(maxt[j]+" ");
        }

        bw.append("\n");
      }
      bw.flush();
      bw.close();


    }

}
