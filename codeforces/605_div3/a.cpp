#include <iostream>
#include <algorithm>
#define lli long long int
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;lli result;
  int a[3] = {0};
  cin>>t;
  while(t>0){
    t--;
    cin>>a[0]>>a[1]>>a[2];
    sort(a, a+3);

    if(a[2]- a[0] > a[2]-a[0]-2 && a[2]-a[0]-2 >= 0){
      a[2] = a[2] -2;
    }
    else if(a[2]- a[0] > a[2]-a[0]-1 && a[2]-a[0]-1 >= 0){
      a[2]--;
    }
    result = 2*(a[2]-a[0]);
    cout<<result<<endl;
  }
	return 0;
}
