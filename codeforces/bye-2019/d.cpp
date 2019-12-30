#include <iostream>
#include <map>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, k, p, q, first = 0;
  cin>>n>>k;
  map<int, int> count;
  for(int i=0; i<=k; i++){
    cout<<"? ";
    for(int j=0; j<=k; j++){
      if(i!=j) cout<<j+1<<" ";
    }
    cout.flush();
    cin>>p>>q;
    count[q]++;
  }
  cout<<"! "<<k+1 - count.begin()->second<<endl;
  return 0;
}
