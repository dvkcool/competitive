#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, ans=0;
	cin >> n;
	int a[n-1];
  int r = 0;
  int b[n-1];
  int c[n];
	for(int i=0; i<(n-1); ++i)
		cin >> a[i];

  b[0] = a[0];
  if(b[0]<0){
    r++;
  }
  for(int i =1; i<(n-1); i++){
    b[i] = b[i-1] + a[i];
    if(b[i]<0){
      r++;
    }
  }
  r++;
  c[0] = r;
  if(r>n){
    cout<<-1<<endl;
    return 0;
  }
  int d[n+1];
  memset(d, 0, sizeof(d));
  d[r] = 1;
  //cout<<"upd "<<d[r]<<" "<<r<<endl;

  for(int i=0; i<(n-1); i++){
    r = r + a[i];
    c[i+1] = r;
    if(r>n){
      cout<<-1<<endl;
      return 0;
    }
    else if(d[r] !=0){
      cout<<-1<<endl;
      return 0;
    }
    else{
      d[r] = 1;
      //cout<<"upd "<<d[r]<<" "<<r<<endl;
    }
  }
  //cout<< d[1]<< d[2]<< d[3]<< d[4] <<d[5]<<endl;
  for(int i=1; i<(n+1); i++){
    if(d[i]==0){
      //cout<<"here3 "<<d[i]<<" "<<i<<endl;
      cout<<-1<<endl;
      return 0;
    }
  }

  for(int i=0; i<n; i++){
    cout<<c[i]<<" ";
  }
  cout<<endl;
	return 0;
}
