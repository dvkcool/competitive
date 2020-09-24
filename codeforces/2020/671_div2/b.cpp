// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  // disjoint set will be of size 2^n -1  => sabse important deduction
  lli i=1, ans = 0;
  lli n, x;
  cin>>n;
  x = (1LL << i) -1;
  x= (x * (x+1))/2;
  while(x<=n){
    n = n -x;
    // cout<<n<<" "<<x<<"\n";
    ans++;
    i++;
    x = (1LL << i) -1;
    x= (x * (x+1))/2;
  }
  cout<<ans<<"\n";
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, i=1;
  cin>>t;//Comment if only one test case
  while(i<=t){
    //cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
