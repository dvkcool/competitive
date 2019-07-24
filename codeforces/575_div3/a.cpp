#include<iostream>
using namespace std;
#define lli long long int
int main(){
  int n;
  cin>>n;
  while(n>0){
    n--;
    lli a, b, c;
    cin>>a>>b>>c;
    cout<<(a+b+c)/2<<endl;
  }
  return 0;
}
