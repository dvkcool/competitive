// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  int n;
  cin>>n;
  int res  = 0;
  int temp, lastOne = -1;
  for(int i=0; i<n; i++){
    cin>>temp;
    if(temp){
      if((lastOne != -1 )&& (i - lastOne != 1)){
        res += (i - lastOne -1);
      }
      lastOne = i;
    }
  }
  cout<<res<<"\n";
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
