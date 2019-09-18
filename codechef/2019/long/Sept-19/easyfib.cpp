#include<iostream>
#define lli long long int
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int fibNum[60];
  lli pow2[60];
  fibNum[0] = 0;
  fibNum[1] = 1;
  int i;
  for(i=2; i<60; i++){
    fibNum[i] = (fibNum[i-1]+fibNum[i-2])%10;
  }
  pow2[0] = 1;
  for(i=1; i<60; i++){
    pow2[i] = pow2[i-1]*2;
  }
  int t; lli n;
  cin>>t;
  while(t>0){
    t--;
    cin>>n;
    for(i=59; i>=0; i--){
      if(pow2[i]<=n){
        //cout<<pow2[i]<<endl;
        break;
      }
    }
    cout<<fibNum[(pow2[i]-1)%60]<<endl;
  }
  return 0;
}
