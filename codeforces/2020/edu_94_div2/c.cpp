// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  string s;
  cin>>s;
  int n;
  cin>>n;
  /*
  si was affected by si-x or si+x
  if si is 0 then both si-x and si+x is 0
  */
  int l = s.length();
  bool e[l];
  memset(e, 0, sizeof(e));
  for(int i=0; i<l; i++){
    if(s[i]=='0'){
      if(i-n>=0) e[i-n] = 1;
      if(i+n <l) e[i+n] = 1;
    }
  }
  bool p = 0;
  for(int i=0; i<l; i++){
    if(s[i]=='1'){
      p = 0;
      if(i-n>=0 && !e[i-n]) p= 1;
      if(i+n <l && !e[i+n]) p = 1;
      if(!p){
        cout<<"-1\n";
        return;
      }
    }
  }
  for(int i=0; i<l; i++){
    if(e[i]) cout<<"0";
    else cout<<"1";
  }
  cout<<"\n";
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
