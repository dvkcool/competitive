#include <iostream>
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin>>t;
  while(t>0){
    t--;
    int n;
    cin>>n;
    lli temp, sum=0, sumxor=0;
    for(int i=0; i<n; i++){
      cin>>temp;
      sum += temp;
      sumxor = sumxor ^ temp;
    }
    if(sum== 2*sumxor){
      cout<<0<<endl;
      cout<<endl;
    }
    else{
      sum += sumxor;
      cout<<2<<endl;
      cout<<sumxor<<" "<<sum<<endl;
    }
  }

  return 0;
}
