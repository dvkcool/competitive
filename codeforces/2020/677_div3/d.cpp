// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  int n, temp;
  cin>>n;
  vector<pair<int, int> > gang;
  for(int i=1; i<=n; i++){
    cin>>temp;
    gang.push_back(make_pair(temp, i));
  }
  sort(gang.begin(), gang.end());
  if(gang[0].first == gang[n-1].first){
    cout<<"NO\n";
  }
  else{
    cout<<"YES\n";
    
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
