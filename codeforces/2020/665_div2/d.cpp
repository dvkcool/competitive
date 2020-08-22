// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define modMax 1000000007
bool vis[100001];
lli subTreesize[100001];
lli n, m;
vector<lli> graph[100001];
vector<lli> result;
void subTree(lli i){
  subTreesize[i] = 1;
  for(lli c: graph[i]){
    if(!vis[c]){
      vis[c] = 1;
      subTree(c);
      subTreesize[i] += subTreesize[c];
    }
  }
  if(i!=1)
  result.push_back((((n-subTreesize[i])%modMax)*((subTreesize[i])%modMax))%modMax);
}
void solveTest(){
  lli x, y;
  cin>>n;
  result.clear();
  for(lli i=1; i<=n; i++) graph[i].clear();
  for(lli i=0; i<n-1; i++){
    cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  lli temp;
  cin>>m;
  vector<lli> factors;
  for(lli i=0; i<m; i++){
    cin>>temp; factors.push_back(temp);
  }
  sort(factors.begin(), factors.end());
  while(m>n-1){
    factors[m-2] = ((factors[m-1]%modMax)*(factors[m-2]%modMax))%modMax;
    m--;
  }
  memset(vis, 0, sizeof(vis));
  memset(subTreesize, 0, sizeof(subTreesize));
  vis[1] = 1;
  subTree(1);
  sort(result.begin(), result.end());
  lli ans = 0;lli e;
  for(lli i=result.size()-1; i>=0; i--){
    e = result[i];
    if(m>0){
      ans = (ans + ((e%modMax)*(factors[m-1] %modMax)) %modMax)%modMax;
      m--;
    }
    else{
      ans = (ans + (e))%modMax;
    }
  }
  cout<<ans%modMax<<"\n";
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  lli t, i=1;
  cin>>t;//Comment if only one test case
  while(i<=t){
    //cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
