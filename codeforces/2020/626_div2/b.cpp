/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);  cout.tie(0);
  int n, m, k;
  cin>>n>>m>>k;
  vector<int> factors;
  for(int i=1; i<=sqrt(k); i++){
    if(k%i ==0){
      factors.push_back(i);
      if(k/i != i){
        factors.push_back(k/i);
      }
    }
  }
  sort(factors.begin(), factors.end());
  vector<int> x, y;
  int temp, prev = 0;
  for(int i=0; i<n; i++){
    cin>>temp;
    if(temp==1 && i== n-1){
      prev++;
      x.push_back(prev);
    }
    else if(temp==1){
      prev++;
    }
    else{
      x.push_back(prev);
      prev = 0;
    }
  }
  prev = 0;
  for(int i=0; i<m; i++){
    cin>>temp;
    if(temp==1 && i== m-1){
      prev++;
      y.push_back(prev);
    }
    else if(temp==1){
      prev++;
    }
    else{
      y.push_back(prev);
      prev = 0;
    }
  }
  lli r = 0;
  for(int xi: x){
    for(int yi: y){
      if(xi*yi >= k){
        for(int z: factors){
          if(z>xi){
            break;
          }
          if(yi >= k/z){
            r += (xi-z+1)*(yi- (k/z) + 1);
          }
        }
      }
    }
  }
  cout<<r<<"\n";


  return 0;
}
