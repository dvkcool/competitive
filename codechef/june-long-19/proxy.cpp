#include <bits/stdc++.h>
using namespace std;
void solve(){
  int d;
  cin >> d;
  char a[d];
  int p = 0;
  int r = ceil(d*0.75);
  int i;
  int count = 0;
  for(i=0; i<d; i++){
    cin >> a[i];
    if(a[i]=='P'){
      p++;
    }
  }
  if(p>=r){
    cout <<0 <<"\n";
  }
  else{
    for(i=2; i<(d-2); i++){
      if(a[i]=='P'){
        continue;
      }
      if(a[i-1]=='P'||a[i-2]=='P'){
        if(a[i+1]=='P'||a[i+2]=='P'){
          p++;
          count++;
          if(p>=r){
            break;
          }
        }
      }
    }
    if(p>=r){
      cout << count <<"\n";
    }
    else{
      cout << -1 <<"\n";
    }
  }
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
