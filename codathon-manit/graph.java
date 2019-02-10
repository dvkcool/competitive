// JAVA program to print all
// paths from a source to
// destination.
import java.util.*;
import java.io.*;

// A directed graph using
// adjacency list representation
public class graph {
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

	// No. of vertices in graph
	private int v;

	// adjacency list
	private ArrayList<Integer>[] adjList;

	//Constructor
	public graph(int vertices){

		//initialise vertex count
		this.v = vertices;

		// initialise adjacency list
		initAdjList();
	}

	// utility method to initialise
	// adjacency list
	@SuppressWarnings("unchecked")
	private void initAdjList()
	{
		adjList = new ArrayList[v];

		for(int i = 0; i < v; i++)
		{
			adjList[i] = new ArrayList<>();
		}
	}

	// add edge from u to v
	public void addEdge(int u, int v)
	{
		// Add v to u's list.
		adjList[u].add(v);
	}

	// Prints all paths from
	// 's' to 'd'
	public void printAllPaths(int s, int d)
	{
		boolean[] isVisited = new boolean[v];
		ArrayList<Integer> pathList = new ArrayList<>();

		//add source to path[]
		pathList.add(s);

		//Call recursive utility
		printAllPathsUtil(s, d, isVisited, pathList);
	}

	// A recursive function to print
	// all paths from 'u' to 'd'.
	// isVisited[] keeps track of
	// vertices in current path.
	// localPathList<> stores actual
	// vertices in the current path
	private void printAllPathsUtil(Integer u, Integer d,
									boolean[] isVisited,
							List<Integer> localPathList) {

		// Mark the current node
		isVisited[u] = true;

		if (u.equals(d))
		{
			//System.out.println(localPathList);
      this.alist.add(localPathList);
			// if match found then no need to traverse more till depth
			isVisited[u]= false;
			return ;
		}

		// Recur for all the vertices
		// adjacent to current vertex
		for (Integer i : adjList[u])
		{
			if (!isVisited[i])
			{
				// store current node
				// in path[]
				localPathList.add(i);
				printAllPathsUtil(i, d, isVisited, localPathList);

				// remove current node
				// in path[]
				localPathList.remove(i);
			}
		}

		// Mark the current node
		isVisited[u] = false;
	}

	// Driver program
	public static void main(String[] args)
	{
		// Create a sample graph

            FastReader s=new FastReader();
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
            int cases = s.nextInt();
            for(int i=0; i<cases; i++){
                //aList = new ArrayList<ArrayList<Integer> >();
                //bList = new ArrayList<ArrayList<Integer> >();
                int m = s.nextInt();
                int n, e, h, a, b, l, k, f, h2;
                n = s.nextInt();
                e = s.nextInt();
                h = s.nextInt();
                graph g = new graph(n);
                for(int j=0; j<e; j++){
                    a = s.nextInt();
                    b = s.nextInt();
                    l = s.nextInt();
                    g.addEdge(a-1, b-1);
                }
                k = s.nextInt();
                f = s.nextInt();
                h2 = s.nextInt();
                graph gr = new graph(k);
                for(int j=0; j<f; j++){
                    a = s.nextInt();
                    b = s.nextInt();
                    l = s.nextInt();
                    gr.addEdge(a-1, b-1);
                }
                g.printAllPaths(0, h-1);
                System.out.println(""+g.aList);
                gr.printAllPaths(0, h2-1);
                System.out.println(""+gr.aList);
                /*
                int rtw = -1;
                for (int im = 0; im < aList.size(); im++) {
                      for (int imt = 0; imt < bList.size(); imt++) {
                          if(aList.get(im).size() != bList.get(imt).size()){
                            continue;
                          }
                          int ye = 0;
                          for(int j =0; j<aList.get(im).size(); j++){
                            if(aList.get(im).get(j) != bList.get(imt).get(j)){
                              break;
                            }
                            else{
                              ye++;
                            }
                          }
                          if(ye == aList.get(im).size()){
                            bw.append("YES\n");
                            rtw = 1;
                            break;
                          }
                      }
                      if(rtw==1){
                        break;
                      }
                }

                if(rtw!=1){
                  bw.append("NO\n");
                }
                */
            }



	}
}

// This code is contributed by Himanshu Shekhar.
