    /* Jai Mata Di */
    #include <bits/stdc++.h>
    using namespace std;
    #define lli long long int
    lli r;
    class edge{
    public:
        int u, v, w;
        edge(int a, int b, int c){
          u = a; v= b; w = c;
        }
    };
    bool compareEdge(edge a, edge b)
    {
        return (a.w < b.w);
    }
    int findParent(int i, int parent[]){
      if(parent[parent[i]] != parent[i]){
        parent[i] = findParent(parent[i], parent);
      }
      return parent[i];
    }
    void unionEdge(int a, int b, int parent[], int size[]){
      int parent_a = findParent(a, parent), parent_b = findParent(b, parent);
      if(parent_a == parent_b){
        return;
      }
      r = r + size[parent_b] * size[parent_a];
      if(size[parent_a] >= size[parent_b]){
        size[parent_a] += size[parent_b];
        parent[parent_b] = parent_a;
      }
      else{
        size[parent_b] += size[parent_a];
        parent[parent_a] = parent_b;
      }
    }
    int next(int a[], int x, int n){
      int start = 0, end = n-1;
      int ans = -1;
      while(start<=end){
        int mid = (start+ end)/2;
        if(a[mid]>= x){
          end = mid -1;
        }
        else{
          ans = mid;
          start = mid+1;
        }
      }
      return ans;
    }
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);  cout.tie(0);
      int n, a, b, w, q, x;
      cin>>n;
      vector<edge> edges;
      for(int i=0; i<(n-1); i++){
        cin>>a>>b>>w;
        edge e(a-1, b-1, w);
        edges.push_back(e);
      }
      sort(edges.begin(), edges.end(), compareEdge);
      cin>>q;
      int parent[n];
      int size[n];
      for(int i=0; i<n; i++){
        parent[i] = i;
        size[i] = 1;
      }
      lli results[n];
      int weights[n];
      int rt  = 0;
      r = 0;
      for(int i=0; i<n; i++){
        weights[rt] = edges[i].w;
        for(int p=i; p<n; p++){
          if(edges[p].w == edges[i].w){
            unionEdge(edges[p].u, edges[p].v, parent, size);
          }
          else{
            break;
          }
          i = p;
        }
        results[rt++] = r;
        //cout<<r<<endl;
      }
      for(int i=0; i<q; i++){
        cin>>x;
        int j = next(weights, x+1, rt);
        if(j!= -1){
          cout<<results[j]<<'\n';
        }
        else{
          cout<<"0\n";
        }
     
      }
      return 0;
    }
