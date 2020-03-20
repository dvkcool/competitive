/* Jai Mata Di */
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
  lli n, k, temp, result;
  cin>>n>>k;
  result = 1;
  lli p = n-k;
  lli count = 0;
  lli me = 998244353;
  lli sum = 0;
  bool e = 0;
  for(int i=0; i<n; i++){
    cin>>temp;
    if(temp > p){
      sum += temp;
        result = (result * (count+1LL))%me;
        count = 0;
        e = 1;
    }
    else if(e) count++;
  }
  cout<<sum<<" "<<result<<"\n";
	return 0;
}
