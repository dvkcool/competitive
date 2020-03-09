/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);  cout.tie(0);
  int t, n, q, temp, p;
  int count[2];
  cin>>t;
  while(t--){
    cin>>n>>q;
    memset(count, 0, sizeof(count));
    for(int i=0; i<n; i++){
      cin>>temp;
      count[(__builtin_popcount(temp))%2]++;
    }
    for(int i=0; i<q; i++){
      cin>>temp;
      p = __builtin_popcount(temp);
      if(p%2==0){
        cout<<count[0]<<" "<<count[1]<<"\n";
      }
      else{
        cout<<count[1]<<" "<<count[0]<<"\n";
      }
    }
  }
  return 0;
}
