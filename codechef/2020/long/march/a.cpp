/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);  cout.tie(0);
  int t, n, m, temp, minPrice;
  int count[51];
  int price[51];
  cin>>t;
  while(t--){
    cin>>n>>m;
    memset(count, 0, sizeof(count));
    memset(price, 0, sizeof(price));
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++){
      cin>>temp;
      count[a[i]]++;
      price[a[i]] += temp;
    }
    minPrice = INT_MAX;
    for(int i=1; i<=m; i++){
      if(count[i]){
        minPrice = min(minPrice, price[i]);
      }
    }
    cout<<minPrice<<"\n";
  }
  return 0;
}
