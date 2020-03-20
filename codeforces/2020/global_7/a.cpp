/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
  int t, n;
  cin>>t;
  while(t--){
    cin>>n;
    if(n==1){
      cout<<"-1\n";
    }
    else{
      cout<<"2";
      n--;
      while(n--){
        cout<<"3";
      }
      cout<<"\n";
    }
  }
	return 0;
}
