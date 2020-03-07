/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define modmax 1000000007
int doDfs(vector<int> graph[],bool *allowed, int y, int n){
  stack<int> st;
  int r = 0;
  int x;
  bool vis[n+1];
  memset(vis, 0, sizeof(vis));
  if(allowed[y]){
    st.push(y);
    r++;
  }
  while(!st.empty()){
    x = st.top();
    st.pop();
    vis[x] = 1;
    for(int z: graph[x]){
      if(allowed[z] && !vis[z]){
        vis[z] = 1;
        st.push(z);
        r++;
      }
    }
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);  cout.tie(0);
  int n, q, x, y;
  cin>>n>>q;
  vector<int> graph[n+1];
  for(int i= 1; i<n; i++){
    cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  vector<int> graphN[n+1];
  queue<int> qt;
  bool vis[n+1];
  memset(vis, 0, sizeof(vis));
  qt.push(1);
  while(!qt.empty()){
    x = qt.front();
    qt.pop();
    vis[x] = 1;
    for(int y: graph[x]){
      if(!vis[y]){
        graphN[x].push_back(y);
        vis[y] = 1;
        qt.push(y);
      }
    }
  }
  bool allowed[n+1];
  for(int i=1; i<=n; i++) allowed[i] = 1;
  for(int i=1; i<=q; i++){
    cin>>x>>y;
    if(x==1){
      allowed[y] = allowed[y] ^ 1;
    }
    else{
      cout<<doDfs(graphN, allowed, y, n)<<"\n";
    }
  }
  return 0;
}
