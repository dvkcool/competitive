// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  string s, t;
  cin>>s>>t;
  int ans = t.length();
  int temp = 0;
  for(int i=0; i<s.length()- t.length() +1 ; i++){
    temp = 0;
    for(int j=0; j<t.length(); j++){
      if(s[i+j]!=t[j]) temp++;
    }
    ans = min(ans, temp);
  }
  cout<<ans<<"\n";
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
