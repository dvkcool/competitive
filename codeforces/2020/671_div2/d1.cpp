// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  // 1 2 3 4 => peak 2 (4-2 = 2  /2  =1 )
  /*
  1 2 3 4 5 => 2, 4 (5/2)
  1 2 3 4 5 6 => 2 4 (5/2)
  1 2 3 4 5 6 7 => 2 4 6 (odd /2)

  */
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++) cin>>a[i];
  sort(a, a+n);
  int k = n/2;
  if(n%2 ==0) k--;

  int j =0, p =k;
  //cout<<k<<"\n";
  vector<int> res;
  for(int i=0; i<n; i++){
    if(i%2 != 0){
      if(j<k) res.push_back(a[j++]);
      else res.push_back(a[p++]);
    }
    else res.push_back(a[p++]);
    // cout<<i<<" "<<j<<" "<<p<<" "<<k<<"\n";
  }
  int y = 0;
  for(int i=1 ;i<n; i++){
    if(i-1>=0 && i+1<n){
      if(res[i]< res[i-1] && res[i] <res[i+1]) y++;
    }
  }
  cout<<y<<"\n";
  for(int i=0; i<n; i++)cout<<res[i]<<" ";
  
  cout<<"\n";
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
