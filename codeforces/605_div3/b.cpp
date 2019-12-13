#include <iostream>
#include <strings.h>
#define lli long long int
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, l, r, u, d, len, i, j, minl;
  string s; char c;
  cin>>t;
  while(t>0){
    t--;
    l =0; r=0; u = 0; d= 0;
    cin>>s;
    for(i=0; i<s.length(); i++){
      if(s[i]=='U') u++;
      else if(s[i]=='L') l++;
      else if(s[i]=='R') r++;
      else {  d++; }
    }
    if(s.length()==0){
      cout<<0<<endl;
      cout<<endl;
      continue;
    }
    else if(min(l, r) ==0 && min(u, d)>0){
      cout<<2<<endl;
      cout<<"UD"<<endl;
      continue;
    }
    else if(min(u,d) ==0 && min(l, r)>0){
      cout<<2<<endl;
      cout<<"LR"<<endl;
      continue;
    }
    len = 2*min(l, r) + 2*min(u, d);
    cout<<len<<endl;
    if(len==0){
      cout<<endl;
      continue;
    }
    for(j=0; j<4; j++){
      if(j==0){
         c = 'R';
         minl = min(l, r);
       }
      else if(j==1){
        c= 'U';
        minl = min(u,d);
      }
      else if(j==2){
        c='L';
        minl = min(l, r);
      }
      else{
        c= 'D';
        minl = min(u,d);
      }
      for(i=0; i<minl; i++){
        cout<<c;
      }
    }
    cout<<endl;
  }
	return 0;
}
