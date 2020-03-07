/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);  cout.tie(0);
  int t, n, k, x, y;
  cin>>n>>k;
  vector<int> res;
  for(int i=1; i<=n; i++){
    cin>>x>>y;
    if(x%k==0 && y%k==0){
      res.push_back(i);
    }
  }
  if(res.size() <k){
    cout<<"-1\n";
  }
  else{
    for(int i=0; i<k; i++){
      cout<<res[i]<<" ";
    }
    cout<<"\n";
  }

  return 0;
}
