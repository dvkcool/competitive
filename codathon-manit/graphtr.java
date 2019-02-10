/* IMPORTANT: Multiple classes and nested static classes are supported */

/*
 * uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;

//import for Scanner and other utility classes
import java.util.*;
*/
import java.io.*;
import java.util.*;
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

class graphtr {
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
    static ArrayList<ArrayList<Integer> > aList;
    static ArrayList<ArrayList<Integer> > bList;
    static class pathstore{
        int u;
        int l;
        pathstore(int a, int b){
            u = a;
            l = b;
        }
    }

     static class Graph {
    public static int v;
    public static ArrayList<pathstore>[] adjList;

    public Graph(int vertices){
        this.v = vertices;
        initAdjList();
    }
    @SuppressWarnings("unchecked")
    public void initAdjList()
    {
        adjList = new ArrayList[v];

        for(int i = 0; i < v; i++)
        {
            adjList[i] = new ArrayList<pathstore>();
        }
    }
    public void addEdge(int u, int v, int l)
    {
        adjList[u].add(new pathstore( v, l));
    }
    public void AllPaths(int s, int d)
    {
        boolean[] isVisited = new boolean[v];
        ArrayList<Integer> pathList = new ArrayList<Integer>();
        AllPathsUtil(s, d, isVisited, pathList);
    }
    public void AllPathsUtil(Integer u, Integer d,
                                    boolean[] isVisited,
                            ArrayList<Integer> localPathList) {
        isVisited[u] = true;
        if (u.equals(d))
        {
            // Do this
            //System.out.println(localPathList);
            ArrayList<Integer> ty = new ArrayList<Integer>();
            ty.addAll(localPathList);
            aList.add(ty);
            isVisited[u]= false;
            return ;
        }
        for (pathstore i : adjList[u])
        {
            if (!isVisited[i.u])
            {

              localPathList.add(i.l);
              AllPathsUtil(i.u, d, isVisited, localPathList);
              localPathList.remove((Integer) i.l);
            }
        }
        isVisited[u] = false;
    }
    }

    static class Rraph {
      public static int v;
      public static ArrayList<pathstore>[] adjList;

   public Rraph(int vertices){
       this.v = vertices;
       initAdjList();
   }
   @SuppressWarnings("unchecked")
   public void initAdjList()
   {
       adjList = new ArrayList[v];

       for(int i = 0; i < v; i++)
       {
           adjList[i] = new ArrayList<pathstore>();
       }
   }
   public void addEdge(int u, int v, int l)
   {
       adjList[u].add(new pathstore( v, l));
   }
   public void AllPaths(int s, int d)
   {
       boolean[] isVisited = new boolean[v];
       ArrayList<Integer> pathList = new ArrayList<>();
       AllPathsUtil(s, d, isVisited, pathList);
   }
   public void AllPathsUtil(Integer u, Integer d,
                                   boolean[] isVisited,
                           ArrayList<Integer> localPathList) {
       isVisited[u] = true;
       if (u.equals(d))
       {
         ArrayList<Integer> ty = new ArrayList<Integer>();
         ty.addAll(localPathList);
         bList.add(ty);
           isVisited[u]= false;
           return ;
       }
       for (pathstore i : adjList[u])
       {
           if (!isVisited[i.u])
           {

             localPathList.add(i.l);
             AllPathsUtil(i.u, d, isVisited, localPathList);
             localPathList.remove((Integer) i.l);
           }
       }
       isVisited[u] = false;
   }
   }

    public static void main(String args[] ) throws Exception {

        FastReader s=new FastReader();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int cases = s.nextInt();
        for(int i=0; i<cases; i++){
            aList = new ArrayList<ArrayList<Integer> >();
            bList = new ArrayList<ArrayList<Integer> >();
            int m = s.nextInt();
            int n, e, h, a, b, l, k, f, h2;
            n = s.nextInt();
            e = s.nextInt();
            h = s.nextInt();
            Graph g = new Graph(n);
            for(int j=0; j<e; j++){
                a = s.nextInt();
                b = s.nextInt();
                l = s.nextInt();
                g.addEdge(a-1, b-1, l-1);
            }
            k = s.nextInt();
            f = s.nextInt();
            h2 = s.nextInt();
            Rraph gr = new Rraph(k);
            for(int j=0; j<f; j++){
                a = s.nextInt();
                b = s.nextInt();
                l = s.nextInt();
                gr.addEdge(a-1, b-1, l-1);
            }
            g.AllPaths(0, h-1);
            gr.AllPaths(0, h2-1);
            int rtw = -1;
            for (int im = 0; im < aList.size(); im++) {
                  if(!(bList.contains(aList.get(im)))){
                    bw.append("NO\n");
                    rtw = 1;
                    break;
                  }
            }
            if(rtw ==1){
              continue;
            }
            for (int im = 0; im < bList.size(); im++) {
                  if(!(aList.contains(bList.get(im)))){
                    bw.append("NO\n");
                    rtw = 1;
                    break;
                  }
            }
            if(rtw ==1){
              continue;
            }
            bw.append("YES\n");
        }
        bw.flush();
        bw.close();

    }
}
