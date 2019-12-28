#include <iostream>
#include <strings.h>
#include <algorithm>
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t, n, s, count, ans, maxIndex; lli sum;
  int a[100001] = {0};
  cin>>t;
  while(t>0){
    t--;
    cin>>n>>s;
    int maxPhrase = 0;
    ans = 0; maxIndex = -1;
    sum = 0; count = 0;
    for(int i=0; i<n; i++){
      cin>>a[i];
    }
    for(int i=0; i<n; i++){
      sum += a[i];
      if(maxPhrase < a[i]){
        maxIndex = i;
        maxPhrase = a[i];
      }
      if(sum > s){
        break;
      }
      count++;
    }
    if(count==n){
      cout<<0<<endl;
      continue;
    }
    cout<<maxIndex+1<<endl;
  }
  return 0;
}
