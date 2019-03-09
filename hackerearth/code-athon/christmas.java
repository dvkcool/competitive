/*
 * Enter your code here. Read input from STDIN. Print your output to STDOUT.
 * Your class should be named CandidateCode.
*/

import java.io.*;
import java.util.*;
public class christmas {
    public static void addpath(Vector<Integer> path, int cn[]){
        int l = path.size();
        for(int i=0; i<l; i++){
            cn[path.get(i)]++;
        }
    }
    public static void findpath(Vector<Vector<Integer>> g, int s, int d, int v, int cn[]){
        LinkedList<Vector<Integer>> q = new LinkedList<Vector<Integer>>();
        Vector<Integer> path = new Vector<>();
        path.add(s);
        q.add(path);
        while (q.size()!=0){
            path = q.poll();
            int last = path.lastElement();
            if(last==d){
                addpath(path, cn);
            }
            for (int i = 0; i < (g.get(last)).size(); i++){
                if(!path.contains((g.get(last)).get(i))){
                    Vector<Integer> newpath = new Vector<>(path);
                    newpath.add((g.get(last).get(i)));
                    q.add(newpath);
                }
            }
        }
    }
    public static void main(String args[] ) throws Exception {
    Scanner sc=new Scanner(System.in);
    int h = sc.nextInt();
    int d = sc.nextInt();
    Vector<Vector<Integer>> g = new Vector<>(h+1);
    for(int i=0; i<(h+1); i++){
        Vector<Integer> v = new Vector<>();
        g.add(v);
    }
    int cn[] = new int[h+1];
    for(int i=0; i<(h-1); i++){
      int e = sc.nextInt();
      int f = sc.nextInt();
      (g.get(e)).add(f);
      (g.get(f)).add(e);
    }
    for(int i=0; i<d; i++){
      int m = sc.nextInt();
      int n = sc.nextInt();
      findpath(g, m, n, h, cn);
    }
    int max =0;
    //find max from counter
    for(int i=0; i<h; i++){
      if(max<cn[i]){
        max = cn[i];
      }
    }
    System.out.println(""+max);
    	//Write code here

   }
}
