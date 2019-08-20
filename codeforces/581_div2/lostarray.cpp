#include<iostream>
using namespace std;
#define lli long long int
int main(){
  int n, l, r;
  cin>>n>>l>>r;
  lli min_sum = 0;
  lli j = 1;
  for(int i=0; i<l; i++){
    min_sum = min_sum + j;
    j = j*2;
  }
  cout<<(min_sum + (n-l))<<" ";
  for(int i=l; i<r; i++){
    min_sum = min_sum + j;
    j = j*2;
  }
  cout<<(min_sum + (n-r)*j/2)<<endl;
  return 0;
}
