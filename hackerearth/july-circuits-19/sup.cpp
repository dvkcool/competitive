#include <bits/stdc++.h>
using namespace std;
char a[1000000];
void solve(){
  cin>>a;
  int i =0;
  int maxlen = 0;
  int tem = 0;
  int o = 0;
  int c = 0;
  for(int i=0; i<1000000; i++){
    if(a[i]=='\0'){
      break;
    }
    if(a[i]=='('){
      if(c!=0){
        maxlen = max((2*min(o,c)), maxlen);
        o = 1;
        c = 0;
      }
      else{
        o++;
      }
    }
    else{
      if(o==0){
        c = 0;
      }
      else{
        maxlen = max((2*min(o,c)), maxlen);
        c++;
      }
    }
  }
  cout << maxlen<<endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cases;
	cin >> cases;
	for(int i=0; i<cases; ++i)
		solve();
	return 0;
}
