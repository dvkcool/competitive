#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n, x, y;
  cin>>t;
  int count[100001];
  int ans;
  while(t>0){
    t--;
    memset(count, 0, 100001*sizeof(count[0]));
    ans = 0;
    cin>>n;
    for(int i=1; i<n; i++){
      cin>>x>>y;
      count[x-1]++;
      count[y-1]++;
    }
    for(int i=0; i<n; i++){
      cin>>x;
      if(x!=0 && count[i]>1 ){
        ans++;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
