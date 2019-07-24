#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int kpos[200001];
void solve(){
  int n, k;
  cin>>n>>k;
  memset(kpos, 0, k*sizeof(kpos[0]));
  int temp;
  int odd_count=0;
  for(int i=0; i<n; i++){
    cin>>temp;
    if(temp%2!=0){
      if(odd_count<=k){
        kpos[odd_count] = i+1;
      }
      odd_count++;
    }
  }
  if(odd_count<k){
    cout<<"NO"<<endl;
    return;
  }
  else if((odd_count-k+1)%2==0){
    cout<<"NO"<<endl;
    return;
  }
  else{
    cout<<"YES"<<endl;
    for(int i=0; i<k-1; i++){
      cout<<kpos[i]<<" ";
    }
    cout<<n<<endl;
  }


}
int main(){
  int n;
  cin>>n;
  while(n>0){
    n--;
    solve();
  }
  return 0;
}
