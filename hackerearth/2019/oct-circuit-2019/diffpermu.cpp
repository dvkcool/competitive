#include<iostream>
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n;
  lli fact[12];
  fact[1] = 1;
  t = 2;
  while(t<12){
    fact[t] = t * fact[t-1];
    t++;
  }
  cin>>t;
  while(t>0){
    t--;
    cin>>n;
    lli s = (n * n) - ((n)*(n+1)/2);
    s = s * fact[n];
    cout<<s<<endl;
  }
}
