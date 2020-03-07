/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define modmax 1000000007
lli power2(lli y){
  lli res = 1;
  lli x = 2;
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
  lli t, n;
  cin>>t;
  while(t--){
    cin>>n;
    if(n<3){
      cout<<"0\n";
    }
    else{
      if(n%2==0){
        cout<<"0\n";
      }
      else{
        n = n-3;
        n = n/2;
        cout<<power2(n)<<"\n";
      }
    }
  }
  return 0;
}
