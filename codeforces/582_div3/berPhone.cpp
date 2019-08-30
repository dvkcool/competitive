#include<iostream>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t>0){
    t--;
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
      cin>>a[i];
    }
    int mint = 1000007;
    int r = 0;
    for(int i=n-1; i>=0; i--){
      if(a[i]>mint && mint != 1000007){
        r++;
      }
      else{
        mint = a[i];
      }
    }
    cout<<r<<endl;
  }

  return 0;
}
