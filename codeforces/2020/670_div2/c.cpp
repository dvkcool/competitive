// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  int n;
  cin>>n;
  int x, y;
  vector<pair<int, int> > edges;
  map<int, int> count;
  int maxl = 0;
  for(int i=0; i<n-1; i++){
    cin>>x>>y;
    edges.push_back({x, y});
    count[x]++;
    count[y]++;
    maxl = max(maxl, count[x]);
    maxl = max(maxl, count[y]);
  }
  int res  = 0;
  for(auto ct: count){
    if(ct.second == maxl){
      res++;
    }
  }
  if(res >1 && maxl > 1){
    for(auto e: edges){
      if(count[e.first] == maxl && count[e.second]!=maxl){
        cout<< e.first<<" "<<e.second<<"\n";
        for(auto et: edges){
          if(count[et.first] ==maxl && et.first != e.first){
            cout<<et.first<<" "<<e.second<<"\n";
            return;
          }
          else if(count[et.second] ==maxl && et.second != e.first){
            cout<<e.second<<" "<<et.second<<"\n";
            return;
          }
        }
      }
      else if(count[e.second] == maxl && count[e.first]!=maxl){
            cout<< e.first<<" "<<e.second<<"\n";
            for(auto et: edges){
              if(count[et.first] ==maxl && et.first != e.second){
                cout<<et.first<<" "<<e.first<<"\n";
                return;
              }
              else if(count[et.second] ==maxl && et.second != e.second){
                cout<<e.first<<" "<<et.second<<"\n";
                return;
              }
            }
          }
    }
  }
  else{
    cout<<edges[0].first<<" "<<edges[0].second<<"\n";
    cout<<edges[0].first<<" "<<edges[0].second<<"\n";
  }


}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  lli t, i=1;
  cin>>t;//Comment if only one test case
  while(i<=t){
    //cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
