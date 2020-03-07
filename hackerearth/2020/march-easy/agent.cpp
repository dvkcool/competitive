/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);  cout.tie(0);
  int n, m, k, x, y, z;
  cin>>n>>m>>k;
  lli house[n+1];
  memset(house, 0, sizeof(house));
  vector<int> agents[n+1];
  lli agent_cost[m+1];
  lli agent_x[m+1];
  lli agent_y[m+1];
  for(int i=1; i<=m; i++){
    cin>>x>>y>>z;
    agent_cost[i] = z;
    agent_x[i] = x;
    agent_y[i] = y;
    for(int j=x; j<=y; j++){
      house[j] += z;
      agents[j].push_back(i);
    }
  }
  lli result = 0;
  bool used[n+1];
  memset(used, 0, sizeof(used));
  for(int i=0; i<k; i++){
    vector<pair<int, int> > h_c;
    for(int j=1; j<=n; j++){
      if(!used[j])
      h_c.push_back(make_pair(house[j], j));
    }
    sort(h_c.begin(), h_c.end());
    result += h_c[0].first;
    used[h_c[0].second] = 1;
    int y = h_c[0].second;
    for(int ag: agents[y]){
      for(int k= agent_x[ag]; k<= agent_y[ag]; k++){
        house[k] -= agent_cost[ag];
      }
    }
  }
  cout<<result<<"\n";
  return 0;
}
