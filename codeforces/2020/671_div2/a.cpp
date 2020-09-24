// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  int n, temp;
  cin>>n;
  string s;
  cin>>s;
  int odd_steps = 0;
  int even_steps = 0;
  int o_o = 0, o_e = 0, e_o = 0, e_e = 0;
  for(int i=1; i<=n; i++){
    temp = s[i-1] - '0';
    if(i%2==0){
      even_steps++;
      if(temp%2==0) e_e++;
      else e_o++;
    }
    else{
      odd_steps++;
      if(temp%2==0) o_e++;
      else o_o++;
    }
  }
  if (odd_steps > even_steps){
    if(o_o > 0) cout<<1<<"\n";
    else cout<<2<<"\n";
  }
  else{
    if(e_e >= 1 ) cout<<2<<"\n";
    else cout<<1<<"\n";
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
