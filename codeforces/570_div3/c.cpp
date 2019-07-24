#include<iostream>
using namespace std;
#define lli long long int
void solve(){
  lli k, n, a, b;
  cin >>k>>n>>a>>b;
  lli mini = b*n;
  lli r = -1;
  if(mini<k){
    lli diff = a-b;
    lli lefto = k-mini-1;
    r = lefto/diff;
    if(r>n)
    r = n;
  }
  cout<<r<<endl;
}
int main(){
  int n;
  cin>>n;
  while(n>0){
    n--;
    solve();
  }
  return 0;
}
