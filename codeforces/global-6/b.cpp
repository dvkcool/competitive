#include <iostream>
#include <strings.h>
#define lli long long int
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; lli n, d, e, f;
  cin>>t; string s;
  while(t>0){
    t--;
    cin>>n;
    d = n/7;
    e = d%2;
    f = n%7;
    if(e==0 && f!=0 && n>14){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }

  }
	return 0;
}
