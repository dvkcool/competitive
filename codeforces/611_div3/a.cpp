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
  cin>>t;
  while(t>0){
    t--;
    int h, m;
    cin>>h>>m;
    lli ans = 0;
    ans = (24-h)*60;
    if(m!=0){
      ans -= 60;
      ans += (60-m);
    }

    cout<<ans<<endl;
  }

  return 0;
}
