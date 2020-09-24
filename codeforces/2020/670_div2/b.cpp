// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  lli n, temp;
  cin>>n;
  lli maxn = INT_MIN;
  lli a[n];
  for(lli i=0; i<n; i++){
    cin>>a[i];
    maxn = max(maxn, a[i]);
  }
  if(maxn == 0)cout<<"0\n";
  else if(maxn < 0){
    for(lli i=0; i<n; i++) a[i] = abs(a[i]);
    sort(a, a+n);
    lli res  = 1;
    for(lli i=0; i<5; i++){
      res = res * a[i];
    }
    cout<<(-1 * res)<<"\n";
  }
  else{
    lli res = 1;
    sort(a, a+n);
    res= a[n-1];
    lli i=0, j = n-2;
    // choose 2 more pairs
    temp = 2;
    while(temp>0){
      temp --;
      if(a[i]*a[i+1] > a[j]*a[j-1]){
        res = res * a[i]*a[i+1];
        i += 2;
      }
      else{
        res = res * a[j]*a[j-1];
          j -= 2;
      }
    }
    cout<<res<<"\n";
  }



}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  lli t, i=1;
  cin>>t;//Comment if only one test case
  while(i<=t){
    //cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
