// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  int n, k;
  cin>>n>>k;
  int temp;
  priority_queue <int> carrot;
  for(int i=0; i<n; i++){
    cin>>temp;
    carrot.push(temp);
  }
  int x = 0;
  while(n<k){
    x = carrot.top();
    carrot.pop();
    if(x%2==0){
      carrot.push(x/2);
      carrot.push(x/2);
    }
    else{
      carrot.push(x/2);
      carrot.push((x/2 )+ 1);
    }
    n++;
  }
  lli res = 0, y;
  while(!carrot.empty()){
    y = (lli) carrot.top();
    res = res + (y*y);
    carrot.pop();
  }
  cout<<res<<"\n";
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1, i=1;
  // cin>>t;//Comment if only one test case
  while(i<=t){
    //cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
