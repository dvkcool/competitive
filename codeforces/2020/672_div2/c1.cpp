// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
  lli res[300001][2];
    lli a[300001];
lli maxASum(lli i, lli eo){
  if(i<0) return 0;
  else if(i==0 && eo == 1) return a[0];
  else if(i==0) return 0;
  else if(res[i][eo] != -1){
    return res[i][eo];
  }
  else if(eo == 1){
    res[i][eo] = max(( a[i] + maxASum(i-1, eo^1)), maxASum(i-1, eo));
    return res[i][eo];
  }
  else if(eo==0){
    res[i][eo] = max((0- a[i] + maxASum(i-1, eo^1)), maxASum(i-1, eo));
    return res[i][eo];
  }

  return 0;
}
void solveTest(){
  lli n, q;
  cin>>n>>q;

  for(lli i=0; i<n; i++){
    cin>>a[i];
    res[i][0] = -1;
    res[i][1] = -1;
  }
  cout<<maxASum(n-1, 1)<<"\n";
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
