#include<bits/stdc++.h>
#define lli long long int
#define MODMAX 1000000007
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k, t;
  cin>>n>>k;
  lli a[8001];
  set<int> num;
  memset(a, 0, 8001*sizeof(a[0]));
  for(int i=0; i<n; i++){
    cin>>t;
    a[t]++;
    num.insert(t);
  }
  int l = num.size();
  lli sum[l];
  int b[l];
  set<int>::iterator itr;
  itr = num.begin();
  sum[0] = a[*itr];
  b[0] = *itr;
  lli sumt = 0;
  int i = 1;
  int j;
  itr++;
  for(; itr!=num.end(); itr++){
    sum[i] = sum[i-1]+a[*itr];
    b[i] = *itr;
    i++;
  }
  sumt = sum[i-1];
  k = min(l, k);
  // 0 len
  lli ans = 1;
  // 1 length
  if(n!=1){
    ans = ans + n;
  }
  lli p =0;
  // 2 - k len
  for(i=2; i<=k; i++){
    p = 0;
    for(j=0; j<l; j++){
      if((j+i)>l){
        break;
      }
      sum[j] =  (a[b[j]] * ((sumt-sum[j])<0 ? (sumt-sum[j]+MODMAX): (sumt-sum[j])))%MODMAX;
      p = (p + sum[j])%MODMAX;
      sum[j] = p;
    }
    sumt = p;
    ans = (ans + sumt)%MODMAX;
  }
  cout<<ans<<endl;
  return 0;
}
