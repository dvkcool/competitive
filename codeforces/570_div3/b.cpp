#include<iostream>
using namespace std;
void solve(){
  int n, k;
  cin >> n>>k;
  int mint = 100000008;
  int maxt = 0;
  int temp;
  for(int i=0; i<n; i++){
    cin>>temp;
    if(temp>maxt){
      maxt = temp;
    }
    if(temp<mint){
      mint = temp;
    }
  }
  int x = mint + k;
  if(x<maxt){
    if((maxt-k)<=x){
      cout<<x<<endl;
      return;
    }
    else{
      cout<<-1<<endl;
      return;
    }
  }
  else{
    if((maxt+k)>=x){
      cout<<x<<endl;
      return;
    }
    else{
      cout<<-1<<endl;
      return;
    }
  }
}
int main(){
  int n;
  cin >> n;
  while(n>0){
    n--;
    solve();
  }
  return 0;
}
