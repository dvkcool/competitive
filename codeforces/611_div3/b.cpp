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
    int n, k;
    cin>>n>>k;
    int ans = n/k;
    if(n%k==0){
      cout<<n<<endl;
    }
    else{
      cout<<ans*k + min(k/2, n%k)<<endl;
    }
  }

  return 0;
}
