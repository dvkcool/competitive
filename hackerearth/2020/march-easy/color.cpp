/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define modmax 1000000007
lli power(lli x,lli y){
  x = x %modmax;
  lli res = 1;
  while(y>0){
    if(y&1){
      res = (res*x) % modmax;
    }
    y = y>>1;
    x = (x*x) % modmax;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);  cout.tie(0);
  lli t, n, m, res;
  cin>>t;
  while(t--){
    cin>>n>>m;
    res = (18 * power(6, m-1))%modmax; // first row
    res = (res * (power(6, n-1)))%modmax; // first column
    res = (res * (power(2, (n-1)*(m-1))))%modmax;
    cout<<res<<"\n";
  }
  return 0;
}
