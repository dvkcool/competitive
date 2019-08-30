#include<iostream>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, t;
  int odd_count =0;
  int even_count = 0;
  cin>>n;
  while(n>0){
    n--;
    cin>>t;
    if(t%2==0){
      even_count++;
    }
    else{
      odd_count++;
    }
  }
  cout<<min(odd_count, even_count)<<endl;

  return 0;
}
