#include <iostream>
#include <strings.h>
#define lli long long int
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
  int n, i, prev= -1, len=1, maxlen= 1;
  cin>>n;
  int a[n], incr[200000] = {0};
  int  decr[200000] = {0};
  for(i=0; i<n; i++){
    cin>>a[i];
  }
  for(i=1; i<n; i++){
    if(a[i]>a[i-1]){
      incr[i] = incr[i-1] +1;
    }
    //cout<<incr[i]<<" ";
    maxlen = max(maxlen, incr[i]+1);
  }
  //cout<<endl;
  for(i=n-2; i>=0; i--){
    if(a[i]<a[i+1]){
      decr[i] = decr[i+1] +1;
    }
    //cout<<decr[i]<<" ";
    maxlen = max(maxlen, decr[i]+1);
  }
  //cout<<endl;
  for(i=0; i<n-2; i++){
    if(a[i]<a[i+2]){
      maxlen = max(maxlen, incr[i]+decr[i+2]+2);
    }
  }
  cout<<maxlen<<endl;

	return 0;
}
