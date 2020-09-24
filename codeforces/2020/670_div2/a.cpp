// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  int n;
  cin>>n;
  int temp, count[103];
  memset(count, 0, sizeof(count));
  for(int i=0; i<n; i++){
    cin>>temp;
    count[temp]++;
  }
  int ans = 0;
  for(int i=0; i<102; i++){
    if(count[i]==0){
      ans = i;
      count[i] = 1;
      break;
    }
  }
  for(int i=0; i<102; i++){
    if(count[i]==1 || count[i]==0){
      ans += i;
      break;
    }
  }
  cout<<ans<<"\n";
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
