#include<iostream>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  int d[1000001];
  memset(d, 0, 1000001*sizeof(d[0]));
  int t;
  while(n>0){
    n--;
    cin>>t;
    d[t]++;
  }
  for(n=1; n<1000001;n++){
    if(d[n]==1){
      cout<<n<<" ";
    }
  }
  return 0;
}
