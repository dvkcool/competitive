/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);  cout.tie(0);
  int t, a, b, c, n, s;
  cin>>t;
  while(t--){
    a= 0; b =0; c =0;
    cin>>n;
    for(int i=1; i<=n; i++){
      cin>>s;
      if(s%2 == 0){
        c = i;
      }
      else{
        if(a==0){
          a = i;
        }
        else{
          b = i;
        }
      }
    }
    if(c){
      cout<<"1\n";
      cout<<c<<"\n";
    }
    else if(a!=0 && b!=0){
      cout<<"2\n";
      cout<<a<<" "<<b<<"\n";
    }
    else{
      cout<<"-1\n";
    }
  }
  return 0;
}
