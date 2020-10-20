// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int

lli nfactnby2(int n){
  if(n==2) return 2;
  if(n==4) return 6;
  if(n==6) return 20;
  if(n==8) return 70;
  if(n==10) return 252;
  if(n==12) return 924;
  if(n==14) return 3432;
  if(n==16) return 12870;
  if(n==18) return 48620;
  if(n==20) return 184756;
  return 1;
}

lli nfact(int n){
  lli r = 1;
  for(int i=1; i<=n; i++){
    r = r * i;
  }
  return r;
}
void solveTest(){
  int n;
  cin>>n;
  lli r = nfactnby2(n);
  r = r * nfact(n/2 -1)*nfact(n/2 -1);
  r = r/2;
  cout<<r<<"\n";
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1, i=1;
  // cin>>t;//Comment if only one test case
  while(i<=t){
    //cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
