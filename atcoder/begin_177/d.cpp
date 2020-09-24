// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define modmax 1000000007
vector<int> graph[200001];
vector<int> order;
vector<int> grev[200001];
bool vis[200001];
int n, m;
void dfs1 (int v) {
    vis[v] = true;
    for (int i=0; i<graph[v].size(); ++i)
        if (!vis[ graph[v][i] ])
            dfs1 (graph[v][i]);
    order.push_back(v);
}
int temp = 0;
void dfs2 (int v) {
    vis[v] = true;
    temp++;
    for (int  i=0; i<grev[v].size(); ++i)
        if (!vis[ grev[v][i] ])
            dfs2 (grev[v][i]);
}
void solveTest(){
  cin>>n>>m;
  int x, y;
  for(int i=0; i<m; i++){
    cin>>x>>y;
    x--; y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
    grev[x].push_back(y);
    grev[y].push_back(x);
  }
  memset(vis, 0, sizeof(vis));
  for (int i=0; i<n; ++i){
    if (!vis[i])
        dfs1 (i);
  }
  int ans = 0;
  memset(vis, 0, sizeof(vis));
  for (int i=0; i<n; ++i) {
      int v = order[n-1-i];
      if (!vis[v]) {
          temp = 0;
          dfs2 (v);
          ans = max(ans, temp);
      }
  }
  cout<<ans<<"\n";
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1, i=1;
  //cin>>t;//Comment if only one test case
  while(i<=t){
    //cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
