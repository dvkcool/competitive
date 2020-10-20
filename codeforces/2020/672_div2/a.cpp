// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  // this is supposed to be easy
  // par samjh nahi aaya
  // bakwas guess kar raha haha -2 ki tayari maybe
  int n, temp;
  cin>>n;
  vector<int> a, b;
  for(int i=0; i<n; i++){
    cin>>temp; a.push_back(temp);
    b.push_back(temp);
  }
  sort(b.begin(), b.end());
  for(int i=0; i<n; i++){
    if(a[i]==b[i]){
      cout<<"YES\n";
      return;
    }
    auto j = lower_bound(b.begin(), b.end(), a[i]+1);
    if(j != b.end() && a[(i+1)%n]==*j && n!=2){
      cout<<"YES\n";
      return;
    }
  }
  cout<<"NO\n";
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, i=1;
  cin>>t;//Comment if only one test case
  while(i<=t){
    //cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
