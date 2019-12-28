#include <iostream>
#include <strings.h>
using namespace std;
int reduce;
int a[200001];
int red[200001];
int n;
int reduceCost( int l, int r,  int d, int cost){
  if(d==0){
    return cost;
  }
  if(l<0 && r>=n){
    return cost;
  }
  while(d!=0){
    if(l<0 && r>=n){
      return cost;
    }
    else if(l>=0 && a[l]==reduce){
      d--;
      l--;
      cost++;
    }
    else if(r<n && a[r]==reduce ){
      d--;
      r++;
      cost++;
    }
    else{
      if(l>0 && r >= n){
        cost++;
        d++;
        l--;
      }
      else if(r<n-1 && l<0){
        cost++;
        d++;
        r++;
      }
      else{
        int x = min(red[l], red[r]);
        if(x== red[l]){
          l = l - red[l] -1;
          cost += (x + 1);
          d += (x+ 1);
        }
        else{
          r = r + red[r] + 1;
          cost += (x + 1);
          d += (x + 1);
        }
      }
    }
    //cout<<"d: "<<d<<endl;
  }
  return cost;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin>>t;
  int s, b, count;
  while(t>0){
    t--;
    cin>>n; s= 0; b = 0;
    for(int i=0; i<(2*n); i++){
      cin>>a[i];
      if(a[i]==1) s++;
      else b++;
    }
    //cout<<"done"<<endl;
    int d = max(s, b) - min(s,b);
    //cout<<d<<endl;
    reduce = min(s, b) == s ? 2 : 1;
    if(d==0){
      cout<<0<<endl;
      continue;
    }
    red[0] = 0;
    red[2*n -1] = 0;
    for(int i=1; i<n; i++){
      if(a[i]==a[i-1]){
        red[i] = red[i-1] +1;
      }
      else{
        red[i] = 0;
      }
    }
    for(int i=(2*n)-2; i>=n; i--){
      if(a[i]==a[i+1]){
        red[i] = red[i+1] +1;
      }
      else{
        red[i] = 0;
      }
    }
    int left = n -1;
    int right = n;
    n = n*2;
    cout<<min(reduceCost(left, right, d, 0), n)<<endl;

  }
}
