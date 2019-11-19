#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, x, y, z;
  cin>>n;
  int a[n][3][2];
  int count[100000] = {0};
  int r[n];
  for(int i=0; i<n-2; i++){
    cin>>x>>y>>z;
    a[x-1][count[x-1]][0]= y;
    a[x-1][count[x-1]][1]= z;
    a[y-1][count[y-1]][0]= x;
    a[y-1][count[y-1]][1]= z;
    a[z-1][count[z-1]][0]= y;
    a[z-1][count[z-1]][1]= x;
    count[x-1]++;
    count[y-1]++;
    count[z-1]++;
  }
  // first
  for(int i=0; i<n; i++){
    if(count[i]==1){
      r[0] = i+1;
      break;
    }
  }
  // second and third
  x = a[r[0]-1][0][0];
  y = a[r[0]-1][0][1];
  if(count[x-1]==2){
    r[1] = x;
    r[2] = y;
  }
  else{
    r[1] = y;
    r[2] = x;
  }
  for(int i=3; i<n; i++){
    for(int j=0; j<3; j++){
      if(a[r[i-1]-1][j][0] == r[i-2] && a[r[i-1]-1][j][1] != r[i-3]){
        r[i] = a[r[i-1]-1][j][1];
        break;
      }
      if(a[r[i-1]-1][j][1] == r[i-2] && a[r[i-1]-1][j][0] != r[i-3]){
        r[i] = a[r[i-1]-1][j][0];
        break;
      }
    }
  }
  for(int i=0; i<n; i++){
    cout<<r[i]<<" ";
  }
  cout<<endl;
	return 0;
}
