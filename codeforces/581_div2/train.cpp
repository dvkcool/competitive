#include<iostream>
using namespace std;
#define lli long long int
int main(){
  string s;
  cin>>s;
  int l = s.length();
  int r =0;
  int flag = 0;
  for(int i=l-1; i>=0; i=i-2){
    if(s[i]=='1' && i!=0){
      flag = 1;
    }
    else if(i==0){
      if(flag!=0){
        r++;
      }
      break;
    }
    r++;
  }
  cout<<r<<endl;
  return 0;
}
