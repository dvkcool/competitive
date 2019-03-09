import java.io.*;
import java.util.*;

public class grapharr{
  static int gcd(int a, int b){
    if (a == 0 || b == 0){
      return 0;
    }
    if (a == b){
      return a;
    }
    if (a > b){
      return gcd(a-b, b);
    }

    return gcd(a, b-a);
  }
  static boolean checkcoprime(int a, int b) {
      if (gcd(a, b) == 1)
          return true;
      else
          return false;
  }
  public static boolean bfs(int adjacency_matrix[][]){
    int source = 0;
    Queue<Integer> queue = new LinkedList<Integer>();
    int number_of_nodes = adjacency_matrix[source].length - 1;
    int[] visited = new int[number_of_nodes + 1];
    int i, element;
    visited[source] = 1;
    queue.add(source);
    while (!queue.isEmpty()){
        element = queue.remove();
        i = element;
        while (i <= number_of_nodes){
          if (adjacency_matrix[element][i] == 1 && visited[i] == 0){
                queue.add(i);
                visited[i] = 1;
            }
            i++;
        }
    }
    boolean connected = false;
    for (int vertex = 1; vertex <= number_of_nodes; vertex++){
        if (visited[vertex] == 1){
            connected = true;
        } else{
            connected = false;
            break;
        }
    }
    return connected;
  }
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        int l = Integer.parseInt(br.readLine().trim());
        String s[] = br.readLine().trim().split(" ");
        int a[] = new int[l];
        int arr[][] = new int[l][l];
        for(int j=0; j<l; j++){
          a[j] =  Integer.parseInt(s[j]);
        }
        for(int j=0; j<(l-1); j++){
          for(int k=0; k<l; k++){
            if(checkcoprime(a[j], a[k])){
              arr[j][k] = 1;
              arr[k][j] = 1;
            }
          }
        }
        if(bfs(arr)){
          System.out.println("0");
          for(int j=0; j<l; j++){
            if(j!=0)
            System.out.print(" ");
            System.out.print(""+a[j]);
          }
        }
        else{
          System.out.println("1");
          for(int j=0; j<l; j++){
            if(j==0){
              System.out.print("29");
            }
            if(j!=0){
              System.out.print(" ");
              System.out.print(""+a[j]);
            }
          }
        }
      }
    }
}
