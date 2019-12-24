#include <iostream>
#include <strings.h>
#include <algorithm>
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t, n, p, k, x;
  cin>>t;
  while(t>0){
    t--;
    cin>>n>>p>>k;
    int x, maxProd = 0;
    int a[n];
    for(int i=0; i<n; i++){
      cin>>a[i];
    }
    sort(a, a+n);
    lli sum[n+1];
    sum[0] = 0;
    sum[1] = a[0];
    if(sum[1] <= p){
      maxProd  = 1;
    }
    for(int i=2; i<=k; i++){
      sum[i] = sum[i-1] + a[i-1];
      if(sum[i]<=p){
        maxProd = i;
      }
    }
    for(int i=k; i<n+1; i++){
      sum[i] = sum[i-k] + a[i-1];
      if(sum[i]<=p){
        maxProd = i;
      }
    }
    cout<<maxProd<<endl;
  }

  return 0;
}
