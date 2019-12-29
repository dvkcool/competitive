#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin>>t;
  while(t>0){
    t--;
    int n, p = 0;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
      cin>>a[i];
    }
    for(int i=1; i<n; i++){
      if(max(a[i], a[i-1]) - min(a[i], a[i-1]) >=2){
        cout<<"YES\n";
        cout<<i<<" "<<i+1<<endl;
        p = 1;
        break;
      }
    }
    if(!p){
      cout<<"NO"<<endl;
    }

  }

  return 0;
}
