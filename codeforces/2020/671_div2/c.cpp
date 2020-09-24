// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  int n, x;
  cin>>n>>x;
  lli a[n];
  int y = 0;
  lli sum = 0;
  for(int i=0; i<n; i++){
    cin>>a[i];
    if(a[i]==x) {
      y++;
      a[i] = 0;
    }
    a[i] -= x;
    sum += a[i];
  }
  if(y==n) cout<<0<<"\n";
  else if(sum==0) cout<<1<<"\n";
  else if(y>=1) cout<<1<<"\n";
  else cout<<2<<"\n";

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
