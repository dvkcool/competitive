// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  string s;
  cin>>s;
  int sum = 0;
  for(char c: s){
    sum += (c-'0');
    sum = sum%9;
  }
  if(sum==0){
    cout<<"Yes\n";
  }
  else{
    cout<<"No\n";
  }
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
