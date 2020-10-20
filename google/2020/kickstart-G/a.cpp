// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  double res = 0;
  lli n; double temp;
  cin>>n;
  double sumOfNl = (n*(n-1))/2; // sum of n-1
  for(int i=0; i<n; i++){
    cin>>temp;
    res =  res + (temp * sumOfNl);
  }
  res = res / (n-1);
  cout<<res<<"\n";

}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1, i=1;
  cin>>t;//Comment if only one test case
  while(i<=t){
    cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
