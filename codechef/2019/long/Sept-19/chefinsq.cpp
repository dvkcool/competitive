#include<iostream>
#include<algorithm>
#define lli long long int
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a[50];
  int t, n, k, r, p;
  cin>>t;
  while(t>0){
    t--;
    r = 1;
    p = 0;
    cin>>n>>k;
    for(int i=0; i<n; i++){
      cin>>a[i];
    }
    sort(a, a+n);
    for(int i=k-2; i>=0; i--){
      if(a[i]==a[k-1]){
        p++;
      }
    }
    for(int i=k; i<n; i++){
      if(a[i]==a[k-1]){
        r++;
      }
      else{
        break;
      }
    }
    if(r==1){
      cout<<1<<endl;
      continue;
    }
    lli maxn = p+1 > r-1 ? p+1 : r-1;
    lli minn = p+1 < r-1 ? p+1 : r-1;
    int y = p+r;
    lli e = 1;
    int w = 1;
    while(y>maxn){
      e = e* y;
      if(e%w==0 && w<=minn){
        e = e/w;
        w++;
      }
      y--;
    }
    while(w<=minn){
      e = e/w;
      w++;
    }
    cout<<e<<endl;
  }
  return 0;
}
