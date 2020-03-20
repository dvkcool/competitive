/* Jai Mata Di */
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
  int t, n;
  lli a;
  lli b[1000000];
  t = 1;
  //cin>>t;
  while(t--){
    cin>>n;
    for(int i=0; i<n; i++) cin>>b[i];
    int prev = 0;
    cout<<b[0]<<" ";
    lli maxt = b[0];
    for(int i=1; i<n; i++){
      cout<<b[i]+maxt<<" ";
      maxt = max(b[i]+maxt, maxt);
    }
    cout<<"\n";

  }
	return 0;
}
