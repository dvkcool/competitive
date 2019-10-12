#include<iostream>
#include<vector>
#include <queue>
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  n=1; q=1;
  cin>>n>>q;
  lli a[n];
  lli b[n];
  vector <int> graph[n];
  vector <int> grap[n];
  int c[n][n];
  int i, j, k, x, y, t;
  char rt;
  for(i=0; i<n-1; i++){
    cin>>x>>y;
      grap[x-1].push_back(y-1);
      grap[y-1].push_back(x-1);
  }
  queue <int> qr;
  qr.push(0);
  while(!qr.empty()){
    t = qr.front();
    qr.pop();
    for(i=0; i<grap[t].size(); i++){
      if(c[t][grap[t][i]]!=1 && c[grap[t][i]][t]!=1){
        graph[t].push_back(grap[t][i]);
        c[t][grap[t][i]] =1;
        c[grap[t][i]][t]=1;
        qr.push(grap[t][i]);
      }
    }
  }
  for(i=0; i<n; i++){
    cin>>a[i];
  }
  for(i=0; i<q; i++){
    cin>>rt;
    for(j=0; j<n; j++){
      b[j] = 0;
    }
    for(j=0; j<n; j++){
      if(a[j]!=0){
        for(k=0; k<graph[j].size(); k++){
          b[graph[j][k]] = a[j];
        }
        if(graph[j].size()>0)
        a[j] = 0;
      }
    }
    for(k=0; k<n; k++){
      a[k] += b[k];
    }

    if(rt=='+'){
      cin>>x>>y;
      a[x-1] += y;
      //cout<<x-1<<" + "<<a[x-1]<<" "<<y<<endl;
    }
    else{
      cin>>x;
      cout<<a[x-1]<<endl;
    }
/*
    cout<<" i: "<<i<<" ";
    for(k=0; k<n; k++){
      cout<<a[k]<<" ";
    }
    cout<<endl;
*/
  }


}
