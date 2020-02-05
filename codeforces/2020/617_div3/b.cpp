/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
  int t; lli n, s;
  cin>>t;
  while(t--){
    cin>>n;
    s = 0;
    while(n>=10){
       s += ((n/10) * 10);
       n = (n%10) + (n/10); // No of cashbacks;
    }
    s += n%10;
    cout<<s<<"\n";
  }
  return 0;
}
