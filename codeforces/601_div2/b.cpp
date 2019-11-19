#include <iostream>
#define lli long long int
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, n, m, a, i, index1, index2;
  lli sum, diff, min1, min2;
  cin>>t;
  while(t>0){
    t--;
    cin>>n>>m;
    min1 = 100000;
    min2 = min1;
    index1 = -1;
    index2 = -1;
    sum = 0;
    for(i=0; i<n; i++){
      cin>>a;
      sum += a;
      if(a<=min1){
        min2 = min1;
        index2 = index1;
        min1 = a;
        index1 = i+1;
      }
      else if(a<=min2){
        min2 = a;
        index2 = i+1;
      }
    }
    if(n==2){
      cout<<-1<<endl;
      continue;
    }
    else if(m<n){
      cout<<-1<<endl;
      continue;
    }
    sum = sum *2;
    diff =0;
    if(m>=n){
      diff = m - n;
      sum += (diff * (min1+ min2));
    }
    cout<<sum<<endl;
    for(i=0; i<n; i++){
      cout<< i+1 << " "<< ((i+1)%n)+1 <<endl;
    }
    for(i=0; i<diff; i++){
      cout<<index1<<" "<<index2<<endl;
    }
  }
	return 0;
}
