
import java.io.*;
import java.util.*;

public class LearningDishesSep{
  static class city{
   int data;
   boolean visited;
   int index;
   List<city> neighbours;

   city(int data, int i)
   {
     this.data=data;
     this.index = i;
     this.neighbours=new ArrayList<>();

   }
   public void addneighbours(city neighbourcity)
   {
     this.neighbours.add(neighbourcity);
   }
   public List<city> getNeighbours() {
     return neighbours;
   }
   public void setNeighbours(List<city> neighbours) {
     this.neighbours = neighbours;
   }
 }
  public static class cook{
       public  int dfsUsingStack(city c[], int start, int w)
   {
     int result =0;
     Stack<city> stack=new  Stack<city>();
     stack.add(c[start]);
     c[start].visited=true;
     while (!stack.isEmpty())
     {
       city element=stack.pop();

       if(element.index == 0){
         if(element.data >= w){
           result++;
         }
         return result;
       }


       if(element.data >= w){
         result++;
       }

       List<city> neighbours=element.getNeighbours();
       for (int i = 0; i < neighbours.size(); i++) {
         city n=neighbours.get(i);
         if(n!=null && !n.visited)
         {
           stack.add(n);
           n.visited=true;

         }
       }
     }
     return result;
   }
  }

  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int t = Integer.parseInt(br.readLine().trim());

      for(int i=0; i<t; i++){
        cook ck = new cook();
        int n = Integer.parseInt(br.readLine().trim());
        String arr[] = br.readLine().trim().split(" ");
        city c[] = new city[n];
        for(int j=0; j<n; j++){
          c[j] = new city(Integer.parseInt(arr[j]), j);
        }
        String path[] = br.readLine().trim().split(" ");
        for(int j=0; j<n-1; j++){
          int q = Integer.parseInt(path[j]);
          c[j+1].addneighbours(c[q-1]);
        }
        int q = Integer.parseInt(br.readLine().trim());
        int prev =0;
        for(int k=0; k<q; k++){
          String s[] = br.readLine().trim().split(" ");
          int v = Integer.parseInt(s[0]);
          int w = Integer.parseInt(s[1]);
          v = v^prev;
          w = w^prev;
          prev = ck.dfsUsingStack(c, v-1, w);
          System.out.println(""+prev);
          if(k!=q-1)
          for(int j=0; j<n; j++){
            c[j].visited = false;
          }
        }
      }
      System.gc();
    }
}
