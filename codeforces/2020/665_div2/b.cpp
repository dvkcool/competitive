// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  int x1, x2, y1, y2, z1, z2;
  cin>>x1>>y1>>z1>>x2>>y2>>z2;
  /*
  combinations:
  00=0 01=0 02=0
  10=0 11=0 12=-2
  20=0 21=2  22=0
  only deciding are  12, 21
  */
  lli sum = 0;
  sum += (2* min(z1, y2));
  int e = min(z1, y2);
  z1 -= e;
  y2 -= e;
  if(z2 - x1 - z1 > 0){
    z2 = z2 - x1 - z1;
    sum = sum - (z2*2);
  }
  cout<<sum<<"\n";
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
