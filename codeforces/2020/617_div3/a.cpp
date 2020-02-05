/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
  int t, n;
  cin>>t;
  while(t--){
    cin>>n;
    int a[n];
    lli sum = 0;
    int count[2] = {0};
    for(int i=0; i<n; i++){
      cin>>a[i];
      sum += a[i];
      count[a[i]%2]++;
    }
    if(sum%2!=0){
      cout<<"Yes\n";
    }
    else{
      if(count[0]>=1 && count[1]>=1){
        cout<<"Yes\n";
      }
      else{
        cout<<"No\n";
      }
    }
  }
  return 0;
}
