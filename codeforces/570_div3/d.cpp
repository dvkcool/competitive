#include<bits/stdc++.h>
using namespace std;
int a[200001];
int b[200001];
void solve(){
  int n;
  cin >> n;
  memset(a, 0, n*sizeof(a[0]));
  memset(b, 0, (n+1)*sizeof(b[0]));
  int t;
  for(int i=0; i<n; i++){
    cin>>t;
    a[t-1]++;
  }
  t = 0;
  int r =0;
  for(int i=0; i<n; i++){
    t = a[i];
    while(t>=0){
      if(b[t]==0){
        b[t]= 1;
        r += t;
        break;
      }
      t--;
    }
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
