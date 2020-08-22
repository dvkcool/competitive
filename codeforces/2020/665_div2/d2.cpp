// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define modMax 1000000007
vector<int> graph[100001];
vector<lli> result;
lli subTreesize[100001];
int n, x, y, m;
void subTree(int i, int p){
  subTreesize[i] = 1;
  for(int c: graph[i]){
    if(c!=p){
      subTree(c, i);
      subTreesize[i] += subTreesize[c];
    }
  }
  if(p!=-1)
  result.push_back((subTreesize[i]*(n-subTreesize[i])));
}
void solveTest(){

  cin>>n;
  result.clear();
  for(int i=0; i<n; i++) graph[i].clear();
  for(int i=1; i<n; i++){
    cin>>x>>y;
    x--;
    y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  cin>>m;
  lli factors[m];
  for(auto &f: factors) cin>>f;
  sort(factors, factors+m);
  while(m> n-1){
    factors[m-2] = (factors[m-2] * factors[m-1])%modMax;
    m--;
  }
  subTree(0, -1);
  sort(result.begin(), result.end());
  lli ans = 0;
  for(int i=n-2; i>=0; i--){
    if(m>0){
      ans = (ans + (result[i]*factors[m-1])%modMax)%modMax;
      m--;
    }
    else{
      ans = (ans + result[i])%modMax;
    }
  }
  cout<<ans<<"\n";
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1, i=1;
  cin>>t;//Comment if only one test case
  while(i<=t){
    //cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
