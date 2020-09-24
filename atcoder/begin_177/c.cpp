// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define modmax 1000000007
void solveTest(){
   int n;
   cin>>n;
   lli a[n];
   for(int i=0; i<n; i++){
     cin>>a[i];
   }
   lli sum = a[n-1];
   lli ans = 0;
   for(int i=n-2; i>=0; i--){
     sum = sum % modmax;
     ans = (ans + (a[i]*sum)%modmax)%modmax;
     sum = sum + a[i];
     sum = sum % modmax;
   }
   cout<<ans<<"\n";
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1, i=1;
  //cin>>t;//Comment if only one test case
  while(i<=t){
    //cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
