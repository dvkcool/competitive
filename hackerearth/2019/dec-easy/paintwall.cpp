#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  int a[1000][1000], t, n, m, k, i, j;
  lli vertical[1000][1000], horizontal[1000][1000], cost, temp;
  cin>>t;
  while(t>0){
    t--;
    cin>>n>>m>>k;
    for(i=0; i<n;i++){
      for(j=0; j<m; j++){
        cin>>a[i][j];
      }
    }
    if((k>n || 2 >m) && (k>m || 2>n)){
        cout<<-1<<endl;
      continue;
    }
    cost = INT_MAX;
    for(i=n-1; i>0; i--){
      horizontal[i][0] = a[i][0] + a[i-1][0];
      for(j=1; j<m; j++){
        horizontal[i][j] = a[i][j] + a[i-1][j];
        horizontal[i][j] += horizontal[i][j-1];
      }
    }
    for(j=m-1; j>0; j--){
      vertical[0][j] = a[0][j] + a[0][j-1];
      for(i=1;i<n; i++){
        vertical[i][j] = a[i][j] + a[i][j-1];
        vertical[i][j] += vertical[i-1][j];
      }
    }
    //check vertical cost kx2
    for(i=k-1; i<n; i++){
      for(j=1; j<m; j++){
        temp = vertical[i][j];
        if(i>=k) temp = temp - vertical[i-k][j];
        if(temp <cost) cost = temp;
      }
    }
    //check horizontal cost 2xk
    for(j=k-1; j<m; j++){
      for(i=1; i<n; i++){
        temp = horizontal[i][j];
        if(j>=k) temp = temp - horizontal[i][j-k];
        if(temp <cost) cost = temp;
      }
    }
    cout<<cost<<endl;
  }
	return 0;
}
