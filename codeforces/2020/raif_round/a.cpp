// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  int n;
  int a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  for(int i=2; i<n-1; i++){
    if(a[i-2]==2 && a[i-1]==2 && (a[i]>1)){
      cout<<"-1\n";
      return;
    }
    if(a[i-2]==3 && a[i-1]==2 && a[i]>1){
      cout<<"-1\n";
      return;
    }
  }
  if(a[n-1] > 1){
    cout<<"-1\n";
    return;
  }
  int st = 1;
  int count[n];
  memset(count, 0, sizeof(count));
  int r = 0;



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
