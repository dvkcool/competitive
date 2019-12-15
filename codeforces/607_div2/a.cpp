#include <iostream>
#include <strings.h>
#define lli long long int
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; string s;
  cin>>t;
  while(t>0){
    t--;
    cin>>s;
    if(s[s.length() -1] == 'o'){
      cout<<"FILIPINO"<<endl;
    }
    else if(s[s.length() -1] == 'u'){
      cout<<"JAPANESE"<<endl;
    }
    else{
      cout<<"KOREAN"<<endl;
    }
  }
	return 0;
}
