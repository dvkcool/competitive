#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, ans=0;
	cin >> n;
	int a[n];
  int b[n];
	for(int i=0; i<n; ++i)
		cin >> a[i];
  for(int i=0; i<n; ++i)
		cin >> b[i];

  for(int i=0; i<n; i++){
    if(a[i]==0){
      continue;
    }
    double d = ((double)((-1 )* b[i] )/a[i]);
    int r = 1;
    for(int j=0; j<n; j++){
      if(i==j){
        continue;
      }
      if(((double)d*a[j])+ b[j]==0){
        r++;
      }
    }
    ans = max(ans, r);
  }
  int r = 0;
  for(int i=0; i<n; i++){
    if(b[i]==0){
      r++;
    }

  }
  ans = max(ans, r);
	cout << ans<<endl;
	return 0;
}
