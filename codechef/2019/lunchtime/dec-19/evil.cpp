#include <iostream>
#include <strings.h>
#include <algorithm>
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  int count[3000001];
  cin>>t;
  while(t>0){
    t--;
    string s;
    cin>>s;
    lli ans = 0; int x =0, a =0, b=0;
    int n = s.length();
    for(int i=1; i<n; i++){
      if(s[i]==s[i-1]) x++;
    }
    for(int i=0; i<n; i++){
      count[i]= x;
      if(i-1>=0 ){
        if(s[i]==s[i-1]) count[i]--;
        else count[i]++;
      }
      if(i+1<n){
        if(s[i]==s[i+1]) count[i]--;
        else count[i]++;
      }
    }
    /*
    for(int i=0; i<n; i++){
      countNotFlip[i]= 0;
      if(i+1<n){
        if(s[i]==s[i+1]) countNotFlip[i]--;
        else countNotFlip[i]++;
      }
    }
    */
    //ans += x;
    a =0; b =x;
    for(int i=0; i<n; i++){
      s[i] = s[i]=='1' ? '0' : '1'; // flip the char
      if(i-1>=0 ){
        if(s[i]==s[i-1]) b++;
        else b--;
      }
      if(i+1<n){
        if(s[i]==s[i+1]) b++;
        else b--;
      }
      ans += b;
    }
    lli prev = ans; int u =0;
    //cout<<prev<<endl;
    for(int j= 1; j<n; j++){
      prev = prev - count[j-1];
      u =0;
      if(s[j]==s[j-1]){
        u++;
      }
      else{
          u--;
      }
      if(j-2>=0){
          if(s[j-1]==s[j-2]){
              u--;
          }
          else{
              u++;
          }
      }
      prev = prev  - ((n-j)*u);
      ans = ans + prev;
      //cout<<prev<<endl;
    }
    cout<<ans<<endl;

  }

  return 0;
}
