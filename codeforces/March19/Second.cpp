#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
  int max = 0;
	for(int i=0; i<n; ++i)
		cin >> a[i];

  int combo = 0;
  for(int i=0; i<n; i++){
    if(a[i]==1){
      combo++;
    }
    else{
      break;
    }
  }
  for(int i=n-1; i>0; i--){
    if(a[i]==1){
      combo++;
    }
    else{
      break;
    }
  }
  if(combo > max){
    max = combo;
  }
  for(int i=0; i<n; ){
    combo = 0;
    while(i<n && a[i]==1){
      i++;
      combo++;
    }
    if(combo > max){
      max = combo;
    }
    if(i<n){
      i++;
    }
  }
  cout<<max<<endl;
	return 0;
}
