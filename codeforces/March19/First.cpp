#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, ans=0;
  int q, r;
	cin>>n;
  cin>>m;
  if(n==m){
    cout<<0<<endl;
  }
  else if(n>m){
    cout<<-1<<endl;
  }
  else{
    while(1){
      if(n>m){
        break;
      }
      else if(n==m){
        cout<<ans<<endl;
        break;
      }
      ans++;
      q = m/n;
      r = m%n;
      if(r!=0){
        cout<<-1<<endl;
        return 0;
      }
      else if(q%3==0){
        n = n*3;
      }
      else{
        n = n*2;
      }
    }
  }
	return 0;
}
