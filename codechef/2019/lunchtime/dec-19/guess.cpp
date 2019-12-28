#include <iostream>
#include <strings.h>
#include <algorithm>
#include <vector>
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  char p[1000001];
  cin>>t;
  while(t>0){
    t--;
    vector<int> result;
    lli m, a, n, r;
    cin>>a>>m;
    for(lli i=m/(a+1); i<=m/a; i++){
      if((m - a*i)>0 && (m - a*i) <= i ){
        if(i % (m - a*i) == 0){
          result.push_back(i);
        }
      }
    }
    cout<<result.size()<<endl;
    for(lli i=0; i<result.size(); i++){
      cout<<result[i]<<" ";
    }
    cout<<endl;
  }

  return 0;
}
