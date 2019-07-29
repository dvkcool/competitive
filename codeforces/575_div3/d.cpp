#include<bits/stdc++.h>
using namespace std;
char a[2001];
int r[2011];
int g[2011];
int b[2011];
void solve(){
  int n, k;
  cin >> n>>k;
  cin>>a;
  for(int i=n; i<n+3; i++){
    r[i]=0;
    g[i]=0;
    b[i]=0;
  }
  for(int i=n-1; i>=0; i--){
    if(i+3 <n){
      r[i] = r[i+3];
      g[i] = g[i+3];
      b[i] = b[i+3];
    }
    else{
      r[i] = 0;
      g[i] = 0;
      b[i] = 0;
    }
    k--;
    k++;
    if(a[i]=='R'){
      r[i]++;
    }
    else if(a[i]=='G'){
      g[i]++;
    }
    else{
      b[i]++;
    }
  }
  // Got rgb present at each point
  int x[3];
  int y[3];
  int z[3];
  int p[3];
  int miny = k;
  for(int i=0; i<(n-k); i++){
    for(int j=0; j<3; j++){
      x[j] = r[i+j] - r[i-j+k-((k-j)%3)+1];
      y[j] = g[i+j] - g[i-j+k-((k-j)%3)+1];
      z[j] = b[i+j] - b[i-j+k-((k-j)%3)+1];
    }
    p[0] = k- ( x[0]+y[1]+z[2]);
    p[1] = k - (y[0]+z[1]+x[2]);
    p[2] = k -( z[0]+x[1]+y[2]);
    for(int j=0; j<3; j++){
      miny = min(miny, p[i]);
    }
  }
  cout<<miny<<endl;


}
int main(){
  int n;
  cin>>n;
  while(n>0){
    n--;
    solve();
  }
  return 0;
}
