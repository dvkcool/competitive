/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);  cout.tie(0);
  int n, ocount=0, ccount=0, t =0;
  bool bad = 0;
  cin>>n;
  string s;
  cin>>s;
  for(char c: s){
    if(c==')'){
      ccount++;
      t--;
    }
    else{
      ocount++;
      t++;
    }
    if(t<0){
      bad = 1;
    }
  }
  if(ocount != ccount){
    cout<<"-1\n";
  }
  else{
    if(!bad){
      cout<<"0\n";
    }
    else{
      lli r =0;
      t = 0;
      int j =0;
      for(int i=0; i<n; i++){
        if(s[i]==')'){
          t--;
        }
        else{
          t++;
        }
        if(t<0){
          j = i+1;
          r++;
          while(j<n && t<0){
            if(s[j]==')'){
              t--;
            }
            else{
              t++;
            }
            j++;
            r++;
          }
          //cout<<r<<" "<<i<< " " << j<<"\n";
          i = j-1;
          //cout<<r<<"\n";
        }
      }
      cout<<r<<"\n";
    }
  }
  return 0;
}
