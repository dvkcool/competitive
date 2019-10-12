#include<iostream>
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  int a[10001];
  lli k, l, m;
  int n, i, tp;
  while(t>0){
    t--;
    cin>>n;
    cin>>k;
    for(i=0; i<n; i++){
      cin>>a[i];
    }
    //complete set
    l = k/n;
    //left or last
    m = k%n;
    if(l%3==1){
      for(i=0; i<n/2; i++){
        tp = a[i];
        a[i] = a[i] ^ a[n-i-1];
        a[n-i-1] = tp;
      }
    }
    else if(l%3==2){
      for(i=0; i<n/2; i++){
        tp = a[n-i-1];
        a[n-i-1] = a[i] ^ a[n-i-1];
        a[i] = tp;
      }
    }
    //
    if(n%2!=0 && l>=1){
      a[n/2] = 0;
    }

    // left in last operation
    for(i=0; i<m; i++){
      a[i] = a[i] ^ a[n-i-1];
    }
    for(i=0; i<n; i++){
      cout<<a[i]<<" ";
    }
    cout<<endl;


  }
}
