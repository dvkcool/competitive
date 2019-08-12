import java.io.*;
import java.util.*;

public class Direct{
  static class edge{
    int u;
    int v;
    int dir;
    int p;
    edge(int ut, int vt, int d, int ps){
      u=ut;
      v=vt;
      dir = d;
      p = ps;
    }
  }
  static class vertex{
    int active;
    int inside;
    vertex(int a, int i){
      active = a;
      inside = i;
    }
  }
  static int partit(edge arr[], int low, int high){
    edge pivot = arr[high];
    int i = (low-1);
    for (int j=low; j<high; j++){
      if (arr[j].v <= pivot.v){
        i++;
        edge temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    edge temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
  }
  static void sor(edge arr[], int low, int high){
    if (low < high){
      int pi = partit(arr, low, high);
      sor(arr, low, pi-1);
      sor(arr, pi+1, high);
    }
  }
  static int partition(edge arr[], int low, int high){
		edge pivot = arr[high];
		int i = (low-1);
		for (int j=low; j<high; j++){
			if (arr[j].u <= pivot.u){
				i++;
				edge temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		edge temp = arr[i+1];
		arr[i+1] = arr[high];
		arr[high] = temp;
		return i+1;
	}
	static void sort(edge arr[], int low, int high){
		if (low < high){
			int pi = partition(arr, low, high);
			sort(arr, low, pi-1);
			sort(arr, pi+1, high);
		}
	}
  public static void main(String args[] ) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int cases = Integer.parseInt(br.readLine().trim());
      for(int i=0; i<cases; i++){
        String s[] = br.readLine().trim().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        edge e[] = new edge[m];
        vertex v[] = new vertex[n+1];
        edge er[] = new edge[m];
        vertex vr[] = new vertex[n+1];
        for(int j=0; j<=n; j++){
          v[j] = new vertex(0, 0);
          vr[j] = new vertex(0, 0);
        }
        for(int j=0; j<m; j++){
          String t[] = br.readLine().trim().split(" ");
          int u = Integer.parseInt(t[0]);
          int r = Integer.parseInt(t[1]);
          e[j] = new edge(u, r, -1, j);
          v[u].active++;
          v[r].active++;
          er[j] = new edge(u, r, -1, j);
          vr[u].active++;
          vr[r].active++;
        }
        if((m%2)==1){
          System.out.println("-1");
          continue;
        }

      /**  HashSet<Integer> vt = new HashSet<Integer>();
        // Check for single edges
        for(int j=0; j<m; j++){
          if((v[e[j].u].active ==1)  && (v[e[j].u].inside ==0)){
            e[j].dir = 0;
            v[e[j].u].active = 0;
            v[e[j].v].inside++;
            vt.add(e[j].v);
            vt.add(e[j].u);
            v[e[j].v].active--;
          }
          else if(v[e[j].v].active ==1 && (v[e[j].v].inside ==0)){
            e[j].dir = 1;
            v[e[j].v].active = 0;
            v[e[j].u].inside++;
            vt.add(e[j].u);
            vt.add(e[j].v);
            v[e[j].u].active--;
          }
        }
**/
        sort(e, 0, m-1);




        // Checking for other values of edges
        for(int j=0; j<m; j++){
          if(e[j].dir == -1){
            if(v[e[j].v].inside > v[e[j].u].inside){
              if((v[e[j].v].active + v[e[j].v].inside)%2 != 0){
                e[j].dir = 1;
                v[e[j].u].active--;
                v[e[j].u].inside++;
                v[e[j].v].active--;
                //System.out.println(" "+e[j].u+" "+e[j].v+" "+e[j].dir+" "+v[e[j].u].active+" "+v[e[j].u].inside+" "+v[e[j].v].active+" "+v[e[j].v].inside);
              }
              else{
                e[j].dir = 0;
                v[e[j].u].active--;
                v[e[j].v].inside++;
                v[e[j].v].active--;
                //System.out.println(" "+e[j].u+" "+e[j].v+" "+e[j].dir+" "+v[e[j].u].active+" "+v[e[j].u].inside+" "+v[e[j].v].active+" "+v[e[j].v].inside);

              }
            }
            else if( (v[e[j].u].inside > v[e[j].v].inside)){
              if((v[e[j].u].active + v[e[j].u].inside)%2 == 0){
                e[j].dir = 1;
                v[e[j].u].active--;
                v[e[j].u].inside++;
                v[e[j].v].active--;
                //System.out.println(" "+e[j].u+" "+e[j].v+" "+e[j].dir+" "+v[e[j].u].active+" "+v[e[j].u].inside+" "+v[e[j].v].active+" "+v[e[j].v].inside);
              }
              else{
                e[j].dir = 0;
                v[e[j].u].active--;
                v[e[j].v].inside++;
                v[e[j].v].active--;
                //System.out.println(" "+e[j].u+" "+e[j].v+" "+e[j].dir+" "+v[e[j].u].active+" "+v[e[j].u].inside+" "+v[e[j].v].active+" "+v[e[j].v].inside);

              }
            }
            else{
              if((v[e[j].u].active + v[e[j].u].inside)%2 == 0){
                e[j].dir = 1;
                v[e[j].u].active--;
                v[e[j].u].inside++;
                v[e[j].v].active--;
                //System.out.println(" "+e[j].u+" "+e[j].v+" "+e[j].dir+" "+v[e[j].u].active+" "+v[e[j].u].inside+" "+v[e[j].v].active+" "+v[e[j].v].inside);
              }
              else{
                e[j].dir = 0;
                v[e[j].u].active--;
                v[e[j].v].inside++;
                v[e[j].v].active--;
                //System.out.println(" "+e[j].u+" "+e[j].v+" "+e[j].dir+" "+v[e[j].u].active+" "+v[e[j].u].inside+" "+v[e[j].v].active+" "+v[e[j].v].inside);
              }
            }

          }
        }
        int res[] = new int[m];
        boolean stopme = false;
        // Checking each vertex if odd or still unknown
        for(int j=1; j<=n; j++){
          if(((v[j].active) !=0) || ((v[j].inside%2) !=0)){
            System.out.println("-1");
            stopme = true;
            break;
          }

        }
        if(stopme){
          sor(e, 0, m-1);
          for(int j=0; j<m; j++){
            if(er[j].dir == -1){
              if(vr[er[j].v].inside > vr[er[j].u].inside){
                if((vr[er[j].v].active + vr[er[j].v].inside)%2 != 0){
                  er[j].dir = 1;
                  vr[er[j].u].active--;
                  vr[er[j].u].inside++;
                  vr[er[j].v].active--;
                  //System.out.println(" "+e[j].u+" "+e[j].v+" "+e[j].dir+" "+v[e[j].u].active+" "+v[e[j].u].inside+" "+v[e[j].v].active+" "+v[e[j].v].inside);
                }
                else{
                  er[j].dir = 0;
                  vr[er[j].u].active--;
                  vr[er[j].v].inside++;
                  vr[er[j].v].active--;
                  //System.out.println(" "+e[j].u+" "+e[j].v+" "+e[j].dir+" "+v[e[j].u].active+" "+v[e[j].u].inside+" "+v[e[j].v].active+" "+v[e[j].v].inside);

                }
              }
              else if( (vr[e[j].u].inside > vr[e[j].v].inside)){
                if((vr[e[j].u].active + vr[e[j].u].inside)%2 == 0){
                  er[j].dir = 1;
                  vr[er[j].u].active--;
                  vr[er[j].u].inside++;
                  vr[er[j].v].active--;
                  //System.out.println(" "+e[j].u+" "+e[j].v+" "+e[j].dir+" "+v[e[j].u].active+" "+v[e[j].u].inside+" "+v[e[j].v].active+" "+v[e[j].v].inside);
                }
                else{
                  er[j].dir = 0;
                  vr[er[j].u].active--;
                  vr[er[j].v].inside++;
                  vr[er[j].v].active--;
                  //System.out.println(" "+e[j].u+" "+e[j].v+" "+e[j].dir+" "+v[e[j].u].active+" "+v[e[j].u].inside+" "+v[e[j].v].active+" "+v[e[j].v].inside);

                }
              }
              else{
                if((vr[er[j].u].active + vr[e[j].u].inside)%2 == 0){
                  er[j].dir = 1;
                  vr[er[j].u].active--;
                  vr[er[j].u].inside++;
                  vr[er[j].v].active--;
                  //System.out.println(" "+e[j].u+" "+e[j].v+" "+e[j].dir+" "+v[e[j].u].active+" "+v[e[j].u].inside+" "+v[e[j].v].active+" "+v[e[j].v].inside);
                }
                else{
                  er[j].dir = 0;
                  vr[er[j].u].active--;
                  vr[er[j].v].inside++;
                  vr[er[j].v].active--;
                  //System.out.println(" "+e[j].u+" "+e[j].v+" "+e[j].dir+" "+v[e[j].u].active+" "+v[e[j].u].inside+" "+v[e[j].v].active+" "+v[e[j].v].inside);
                }
              }

            }
          }
          for(int j=0 ; j<m; j++){
            res[er[j].p] = er[j].dir;
          }
          for(int j=0; j<m; j++){
            if(j!=0){
              System.out.print(" ");
            }
            System.out.print(""+res[j]);
          }
          System.out.println();
          continue;

        }
        for(int j=0 ; j<m; j++){
          res[e[j].p] = e[j].dir;
        }

        // Else printing everything
        for(int j=0; j<m; j++){
          if(j!=0){
            System.out.print(" ");
          }
          System.out.print(""+res[j]);
        }
        System.out.println();
      }
    }
}
