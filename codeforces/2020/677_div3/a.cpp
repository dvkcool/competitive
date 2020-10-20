// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
    int x;
    cin>>x;
    int y = (x%10);
    int res = 10 * (y-1) ;
    int u = 0;
    while(x>0){
      u++;
      x = x/10;
    }
    res = res + (u*(u+1))/2;
    cout<<res<<"\n";
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
