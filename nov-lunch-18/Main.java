import java.io.*;
import java.util.*;
import java.math.BigInteger;
/**
 class Graph{
  public int numVertices;
  public LinkedList<Integer> adjLists[];

  Graph(int vertices){

      numVertices = vertices+1;
      adjLists = new LinkedList[vertices];

      for (int i = 0; i < vertices; i++)
          adjLists[i] = new LinkedList();
  }

  void addEdge(int src, int dest){
      adjLists[src].add(dest);
  }
}
**/

public class Main{
  /*
  static void put_index(int a[], int l){
    g = new Graph(l);
    for(int i = 0; i<l; i++){
      for(int j= i+1; j<l; j++){
        if(a[i]==a[j]){
          g.addEdge(i, j);
        }
      }
    }
  }
  static boolean checktes(int m, int l){
    for(int i=0; i<l; i++){
      if(i<=l){
        for(int j=0; j<g.adjLists[i].size(); j++){
          if(g.adjLists[i].get(j) > l){
            return false;
          }
        }
      }
      else{
        for(int j=0; j<g.adjLists[i].size(); j++){
          if(g.adjLists[i].get(j) <= l){
            return false;
          }
        }
      }
    }
    return true;
  }
*/
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        int n = Integer.parseInt(s[0]);
        int k = Integer.parseInt(s[1]);
        int a[] = new int[n];
        BigInteger sum = BigInteger.ZERO;
        BigInteger sumt[] = new BigInteger[n];
        String b[] = br.readLine().trim().split(" ");
        for(int j=0; j<n; j++){
          long kr = (long) Math.pow(k, Integer.parseInt(b[j]));
          sum = sum.add(BigInteger.valueOf(kr));
          sumt[j] = sum;
        }
        BigInteger max = BigInteger.ZERO;
        int r = 0;
        for(int j=0; j<n; j++){
          BigInteger q = sumt[j].multiply(sum.subtract(sumt[j]));
          if(max.compareTo(q) < 0){
            r = j;
            max = q;
          }
        }
        r++;
        System.out.println(""+r);
      }
    }
}
