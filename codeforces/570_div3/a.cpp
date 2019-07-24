#include<iostream>
using namespace std;
int sum4(int n){
  int x = 0;
  while(n>0){
    x = x+ (n%10);
    n = n/10;
  }
  if(x%4==0){
    return 1;
  }
  return 0;
}
int main(){
  int n;
  cin >>n;
  for(int x = n; ; x++){
    if(sum4(x)){
      cout<<x<<endl;
      return 0;
    }
  }
  return 0;
}
