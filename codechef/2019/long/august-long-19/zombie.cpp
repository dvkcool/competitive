#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;
int a[100001];
int b[100001];
int n;
void setRadiation(int i, int t){
  int l = max(i-t, 0);
  int h = min(n-1, i+t);
  /*Naive
  for(i=l; i<=h; i++){
    a[i]++;
  }
  */
  a[l]++;
  a[h+1]--;

}
void makeArray(){
  for(int i=1; i<n; i++){
    a[i] += a[i-1];
  }
}
void solve(){
  n=0;
  cin>>n;
  memset(a, 0, n*sizeof(a[0]));
  memset(b, 0, n*sizeof(b[0]));
  int t;
  for(int i=0; i<n; i++){
    cin>>t;
    setRadiation(i, t);
  }
  makeArray();
  sort(a, a+n);
  for(int i=0; i<n; i++){
    cin>>b[i];
  }
  sort(b, b+n);
  for(int i=(n-1); i>=0; i--){
    //cout<<a[i]<<" "<<b[i]<<endl;
    if(b[i]!=a[i]){
      cout<<"NO\n";
      return;
    }
  }
  cout<<"YES\n";
}
int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(0);
  int cases;
  cin>>cases;
  while(cases){
    cases--;
    solve();
  }
  return 0;
}
