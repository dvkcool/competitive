// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  int n;
  cin>>n;
  int a[n], b[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
    b[i] = a[i];
  }
  sort(a, a+n);
  if(a[0]==a[n-1]){
    cout<<"-1\n";
  }
  else{
    for(int i=0; i<n-1; i++){
      if(a[n-1]==b[i] && b[i+1]!=a[i]){
        cout<<i+1<<"\n";
        return;
      }
    }
    for(int i=0; i<n-1; i++){
      if(a[n-1]==b[i] && b[i+1]!=a[i]){
        cout<<i+1<<"\n";
        return;
      }
    }
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, i=1;
  cin>>t;//Comment if only one test case
  while(i<=t){
    //cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
