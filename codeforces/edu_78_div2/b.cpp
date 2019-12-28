#include <iostream>
#include <algorithm>
#define lli long long int
using namespace std;
lli diff[1000000];
int maxl = 0;
void precompute(){
  int i = 1;
  lli sum = 0;
  while(maxl<1000000){
    sum = sum +i;
    diff[maxl++]  = sum;
    i++;
  }
}
int main(){
    int t;
    cin>>t;
    precompute();
    while(t>0){
        t--;
        int a, b;
        cin>>a>>b;
        lli d = a + b;
        lli x = max(a, b);
        x = x*2;
        if(a==b){
          cout<<0<<endl;
          continue;
        }
        int j = 0;
        while(j<maxl){
          if((d+diff[j])%2==0 && d+diff[j] >= x){
            cout<<j+1<<endl;
            break;
          }
          j++;
        }
    }
    return 0;
}
