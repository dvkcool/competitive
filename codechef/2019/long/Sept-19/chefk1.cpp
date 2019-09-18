#include<iostream>
#define lli long long int
using namespace std;
int main(){
  int t;
  lli n, m;
  cin>>t;
  while(t>0){
    t--;
    cin>>n>>m;
    if(n==1){
      if(m==0){
        cout<<0<<endl;
        continue;
      }
      else if(m==1){
        cout<<1<<endl;
        continue;
      }
      else{
        cout<<-1<<endl;
        continue;
      }
    }
    else if(m<(n-1) || m>( (n*(n+1))/2)){
      cout<<-1<<endl;
      continue;
    }
    else{
      if(n==2){
        if(m==1){
          cout<<1<<endl;
          continue;
        }
        else if(m==2 || m==3){
          cout<<2<<endl;
          continue;
        }
      }
      if(m==(n+1)){
        cout<<2<<endl;
        continue;
      }
      else if(m<=n){
        cout<<2<<endl;
        continue;
      }
      else if(m<=2*n){
        cout<<3<<endl;
        continue;
      }
      else if(n%2==0){
        lli p = n/2;
        lli r = m-(2*n);
        if(r%p==0){
          cout<<(3+r/p)<<endl;
          continue;
        }
        else{
          cout<<(4+r/p)<<endl;
          continue;
        }
      }
      else{
        lli p = n/2;
        lli r = m-(2*n);
        if(r%n==0){
          cout<<(3+(2*(r/n)))<<endl;
          continue;
        }
        else{
          if(r%n<=p){
            cout<<(4+(2*(r/n)))<<endl;
            continue;
          }
          else{
            cout<<(5+(2*(r/n)))<<endl;
            continue;
          }

        }
      }
    }
  }
  return 0;
}
