#include <iostream>
#include <algorithm>
#define lli long long int
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
  int t, i;
  cin>>t;
  lli xprev, xnext, ans, dprev;
  lli height[100001];
  lli diff[100001];
  lli d[100001];
  int n;
  while(t>0){
    t--;
    xprev = 0;
    cin>>n;
    cin>>xprev;
    cin>>height[0];
    dprev = 0;
    for(i=0; i<(n-1); i++){
      cin>>xnext;
      cin>>height[i+1];
      diff[i] = xnext-xprev;
      d[i] = dprev + diff[i];
      dprev = diff[i];
      xprev = xnext;
    }
    d[n-1] = diff[n-2];
    sort(height, height+n);
    sort(d, d+ n);
    ans = 0;
    for(i=0;i<n; i++){
      //cout<<height[i]<<" "<<d[i]<<endl;
      ans = ans + (height[i]*d[i]);
    }
    cout<<ans<<endl;
  }

	return 0;
}
