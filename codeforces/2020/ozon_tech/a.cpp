/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t, n;
  cin>>t;
  while(t--){
    cin>>n;
    int a[n];
    int b[n];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    sort(a, a+n);
    sort(b, b+n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<"\n";
    for(int i=0; i<n; i++) cout<<b[i]<<" ";
    cout<<"\n";
  }

  return 0;
}
