#include <iostream>
#include <strings.h>
#include <algorithm>
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t, x;
  int a[3];
  cin>>t;
  while(t>0){
    t--;
    cin>>a[0]>>a[1]>>a[2];
    sort(a, a+3);
    if(a[1]==a[2] && a[2]==a[0]){
      cout<<"Yes"<<endl;
      continue;
    }
    if(a[2] > a[1]+a[0]+1){
      cout<<"No"<<endl;
    }
    else{
      cout<<"Yes"<<endl;
    }
  }

  return 0;
}
