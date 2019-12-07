#include <iostream>
#define lli long long int
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;lli len, width, result;
  cin>>t;
  while(t>0){
    t--;
    cin>>len>>width;
    result = max(len, width)/min(len,width);
    cout<<result<<endl;
  }
	return 0;
}
