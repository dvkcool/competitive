// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  int n;
  cin>>n;
  lli a[n], b[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
    b[i] = a[i];
  }
  sort(a, a+n);
  for(int i=0; i<n; i++){
    if(a[i]!=b[i] && ((a[i]%a[0])!=0 || (b[i]%a[0]!=0)) ){
      cout<<"NO\n";
      return;
    }
    //cout<<a[i]<<" "<<b[i]<<"\n";
  }
  cout<<"YES\n";
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
