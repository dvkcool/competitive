#include <iostream>
#include <strings.h>
#include <algorithm>
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t, a, b, c, r, dmin, dmax;
  cin>>t;
  while(t>0){
    t--;
    cin>>a>>b>>c>>r;
    int x = a;
    a = min(a, b);
    b = max(x, b);
    dmin = c - r;
    dmax = c + r;
    if(dmax< a){
      cout<<(b-a)<<endl;
    }
    else if(dmin > b){
      cout<<(b-a)<<endl;
    }
    else if(dmin >=a && dmax <= b){
      cout<<(b-a - (dmax -dmin))<<endl;
    }
    else if(dmin<= a && dmax >=b){
      cout<<0<<endl;
    }
    else if(dmin >=a && dmax >=b){
      cout<<(dmin-a)<<endl;
    }
    else if(dmin<=a && dmax<=b){
      cout<<(b-dmax)<<endl;
    }
  }

  return 0;
}
