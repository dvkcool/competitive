#include<iostream>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q, i, j, t, m;
  int a[n];
  for(i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a, a+n);
  for(i=0; i<q; i++){
    cin>>j;
    t = j;
    m = 0;
    while(t>0 && m<n){
      if(a[m]>t){
        t = t - (t/a[m])*a[m];
      }
      m++;
    }
    if(t==0){
      cout<<"YES"<<endl;
      continue;
    }
    m= n-1; t= j;
    while(t>0 && m>=0){
      if(a[m]>t){
        t = t - (t/a[m])*a[m];
      }
      m--;
    }
    if(t==0){
      cout<<"YES"<<endl;
      continue;
    }
    cout<<"NO"<<endl;
    continue;
  }
  return 0;
}
