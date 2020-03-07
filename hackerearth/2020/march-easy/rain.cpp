/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);  cout.tie(0);
  lli t, l, r, s, p;
  cin>>t;
  while(t--){
    cin>>l>>r>>s;
    p = l/s;
    if(l%s!=0){
      p++;
    }
    if(p*s >= l && p*s <=r){
      cout<<p<<" ";
      p = r/s;
      cout<<p<<" \n";
    }
    else{
      cout<<"-1 -1\n";
    }
  }
  return 0;
}
