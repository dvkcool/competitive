#include <iostream>
#include <strings.h>
#include <vector>
#define lli long long int
using namespace std;
void solve(){
  int i, j, done; string s, c; char temp;
  cin>>s>>c;
  if(s<c){
    cout<<s<<endl;
  }
  else{
    done =0;
    for(i=0; i<s.length() && i<c.length(); i++){
      if(s[i]==c[i] && c[i]!='A'){
        for(j=i+1; j<s.length(); j++){
          if(s[j]<c[i]){
            temp = s[j];s[j] = s[i];s[i] = temp;
            done = 1;cout<<s<<endl;return;
          }
        }
      }
      else if(s[i]>c[i]){
        vector<int> second;
        for(j=i+1; j<s.length(); j++){
          if(s[j] < c[i]){
            temp = s[j];s[j] = s[i];
            s[i] = temp;done = 1; cout<<s<<endl; return;
          }
          else if(s[j]==c[i]){
            second.push_back(j);
          }
        }
        if(second.size()==0){
          cout<<"---"<<endl;done = 1;return;
        }
        else{
          for(j=0; j<second.size(); j++){
            temp = s[second[j]];s[second[j]] = s[i];
            s[i] = temp;
            if(s<c){
              cout<<s<<endl;
              done =1;return;
            }
            temp = s[second[j]];s[second[j]] = s[i];
            s[i] = temp;
          }
        }
        if(!done){
          cout<<"---"<<endl; done =1;return;
        }
      }
    }
    if(!done){
      if(s<c){
        cout<<s<<endl;
      }
      else{
        cout<<"---"<<endl;
      }
    }
  }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
  cin>>t;
  while(t>0){
    t--; solve();
  }
	return 0;
}
