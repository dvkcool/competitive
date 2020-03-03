/* Jai Mata Di */
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  lli n, m;
  cin>>n>>m;
  bool prev[m];
  bool easy = 0;
  memset(prev, 0, sizeof(prev));
  lli a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
    if(prev[a[i]%m]){
      easy = 1;
    }
    prev[a[i]%m] = 1;
  }
  if(easy){
    cout<<"0\n";
  }
  else{
    lli ans = 1;
    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        ans = (ans * ((abs(a[i]-a[j])%m)))%m;
        ans = ans % m;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
