// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  int n; cin>>n;
  lli prev=0, temp =0, result = 0;
  while(n--){
    cin>>temp;
    if(temp<prev){
      result+= (prev-temp);
    }
    else{
      prev= temp;
    }
  }
  cout<<result<<"\n";
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1, i=1;
  //cin>>t;//Comment if only one test case
  while(i<=t){
    //cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
