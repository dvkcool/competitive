#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <algorithm>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, k, p, q, first = 0;
  cin>>n>>k;
  set<int> query;
  set<int>::iterator itr;
  int a[n];
  for(int i=0; i<n; i++) a[i] = -1;
  for(int i=1; i<=k; i++){
    query.insert(i);
  }
  int j = k;
  for(int i=1; i<=n; i++){
    if(j>n){
      break;
    }
    cout<<"? ";
    for(itr = query.begin(); itr!=query.end(); ++itr){
      cout<<*itr<<" ";
    }
    cout.flush();
    cin>>p>>q;
    a[p-1] = q;
    query.erase(p);
    j++;
    query.insert(j);
  }
  cout<<"? ";

  if(n-k+1 >=k){
    int i = 1;
    int j = 0;
    vector<int> que;
    while(i<=k && j<n){
      if(a[j]!=-1){
        cout<<j+1<<" ";
        que.push_back(a[j]);
        i++; j++;
      }
      else{
        j++;
      }
    }
    cout.flush();
    cin>>p>>q;
    sort(que.begin(), que.end());
    for(i=0; i<k; i++){
      //cout<<que[i]<<" ";
      if(que[i]==q){
        cout<<"! "<<i+1<<endl;
      }
    }
  }

  return 0;
}
