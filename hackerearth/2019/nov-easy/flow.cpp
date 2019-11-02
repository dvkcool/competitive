#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n, m, x, y;
  int inDeg[200001];
  int outDeg[200001];
  int connection[200001];
  cin>>t;
  while(t>0){
    t--;
    cin>>n>>m;
    int d = 0;
    if(n==1){
      cout<<"Yes"<<endl;
      d =1;
    }
    if(d==1){
        for(int i=0; i<m; i++){
            cin>>x>>y;
        }
        continue;
    }
    memset(inDeg, 0, (n+1)*sizeof(inDeg[0]));
    memset(outDeg, 0, (n+1)*sizeof(outDeg[0]));
    memset(connection, 0, (n+1)*sizeof(connection[0]));
    for(int i=0; i<m; i++){
      cin>>x>>y;
      outDeg[x]++;
      inDeg[y]++;
      connection[x] = y;
    }
    for(int i=1; i<=n; i++){
      if(inDeg[i]!= 1 && outDeg[i]!=1){
        cout<<"No"<<endl;
        d =1;
        break;
      }
    }
    if(d==0){
      int s = 1;
      int t = 0;
      while(t<n){
          s = connection[s];
          t++;
      }
      if(s==1){
          cout<<"Yes"<<endl;
      }
      else{
          cout<<"No"<<endl;
      }

    }
  }
  return 0;
}
