// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int prime[1000001];
bool e = 0;
int totaln;
void checkallFactors(){
  for(int i=0; i<1000001; i++){
    if(prime[i]!=0 && prime[i]>2){
      return false;
    }
  }
}
void markFactors(int n){
  if(n%2 == 0){
    if(prime[2]) e = 1;
    prime[2]++;
    while (n % 2 == 0)
      {
          n = n/2;
      }
  }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        if(n%i ==0 ){
          if(prime[i]) e = 1;
          prime[i]++;
          while (n % i == 0)
          {
              n = n/i;
          }
        }
    }
    if (n > 2){
        if(prime[n]) e = 1;
        prime[n]++;
    }
}
void solveTest(){
  int n;
  cin>>n;
  totaln = n;
  int temp;
  for(int i=0; i<n; i++){
    cin>>temp;
    markFactors(temp);
  }
  if(e){
    cout<<"pairwise coprime\n";
  }
  else if(checkallFactors()){
    cout<<"setwise coprime\n";
  }
  else{
    cout<<"not coprime\n";
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1, i=1;
  //cin>>t;//Comment if only one test case
  while(i<=t){
    //cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
