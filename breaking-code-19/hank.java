import java.io.*;
import java.util.*;

public class hank{
  public static int V = 3;

	// This function returns true if graph
	// G[V][V] is Bipartite, else false
	public static boolean isBipartiteUtil(int G[][], int src,
										int colorArr[])
	{
		colorArr[src] = 1;

		// Create a queue (FIFO) of vertex numbers and
		// enqueue source vertex for BFS traversal
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(src);

		// Run while there are vertices in queue
		// (Similar to BFS)
		while (!q.isEmpty())
		{
			// Dequeue a vertex from queue
			// ( Refer http://goo.gl/35oz8 )
			int u = q.getFirst();
			q.pop();

			// Return false if there is a self-loop
			if (G[u][u] == 1)
			return false;

			// Find all non-colored adjacent vertices
			for (int v = 0; v < V; ++v)
			{
				// An edge from u to v exists and
				// destination v is not colored
				if (G[u][v] ==1 && colorArr[v] == -1)
				{
					// Assign alternate color to this
					// adjacent v of u
					colorArr[v] = 1 - colorArr[u];
					q.push(v);
				}

				// An edge from u to v exists and
				// destination v is colored with same
				// color as u
				else if (G[u][v] ==1 && colorArr[v] ==
										colorArr[u])
					return false;
			}
		}

		// If we reach here, then all adjacent vertices
		// can be colored with alternate color
		return true;
	}

	// Returns true if G[][] is Bipartite, else false
	public static boolean isBipartite(int G[][])
	{
		// Create a color array to store colors assigned
		// to all veritces. Vertex/ number is used as
		// index in this array. The value '-1' of
		// colorArr[i] is used to indicate that no color
		// is assigned to vertex 'i'. The value 1 is used
		// to indicate first color is assigned and value
		// 0 indicates second color is assigned.
		int colorArr[] = new int[V];
		for (int i = 0; i < V; ++i)
			colorArr[i] = -1;

		// This code is to handle disconnected graoh
		for (int i = 0; i < V; i++)
		if (colorArr[i] == -1)
			if (isBipartiteUtil(G, i, colorArr) == false)
			return false;

		return true;
	}
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        V = n;
        int G[][] = new int[n][n];
        for(int j=0; j<n; j++){
          for(int k=0; k<n; k++){
            if(j==k){
              continue;
            }
            G[j][k] = 1;
          }
        }
        for(int j=0; j<m; j++){
          String st[] = br.readLine().trim().split(" ");
          int a = Integer.parseInt(st[0]);
          int b = Integer.parseInt(st[1]);
          a--; b--;
          G[a][b] = 0;
          G[b][a] = 0;
        }
        if(isBipartite(G)){
          bw.append("YES\n");
        }
        else{
          bw.append("NO\n");
        }
      }
      bw.flush();
      bw.close();
    }
}
