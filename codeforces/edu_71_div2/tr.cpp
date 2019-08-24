#include<iostream>
#include<algorithm>
#define lli long long int
using namespace std;
void solve(){
  int n;
  lli a, b;
  cin>>n>>a>>b;
  string s;
  cin>>s;
  lli cost = b;
  int h = 1;
  int e = 0;
  for(int i=0; i<n; i++){
    if(s[i]=='0'){
      e++;
    }
  }
  for(int i=0; i<n-1; i++){
    if(s[i+1]=='0'){
      if(s[i]=='1'){
        cost = cost + a + (2*b);
        //cout<<"this: "<<cost<<endl;
        if(i+1==n-1){
          continue;
        }
        if(a<b){
          h = 1;
          cost = cost + (2*a) + b;
        }
        else{
          h = 2;
          cost = cost + a + (2 * b);
        }
        //cout<<"this: "<<cost<<endl;
        i++;
        continue;
      }
      if(h==1){
        cost = cost + a + b;
      }
      else{
        if(a<b){
          h = 1;
          cost = cost + (2*a) + b;
        }
        else{
          h = 2;
          cost = cost + a + (2 * b);
        }
      }
    }
    else{
      if(h==1){
        h = 2;
        cost = cost + (2*a) + (2*b);
      }
      else{
        cost = cost + a + (2*b);
      }
    }
    //cout<<h<<" "<<cost<<endl;
  }
  if(h==2){
    cost = cost + (2*a) + b;
  }
  else{
    cost = cost + a + b;
  }
  if(e==n && n!=2){
    cost = cost - a - b;
  }
  cout<<cost<<endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t>0){
    t--;
    solve();
  }
  return 0;
}
