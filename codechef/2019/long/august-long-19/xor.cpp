#include<iostream>
#include<algorithm>
#include <cstring>
#define lli long long int
using namespace std;
int a[100001];
struct PosXOR
{
public:
    int val;
    int pos;

    //PosXOR(int k, int s) : val(k), pos(s) {}

    bool operator < (const PosXOR& str) const
    {
        return (val < str.val);
    }
};
PosXOR posxor[100001];
int n;
void solve(){
  n=0;
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  posxor[0].val = a[0];
  posxor[0].pos = 0;
  for(int i=1; i<n; i++){
    a[i] = a[i] ^ a[i-1];
    posxor[i].val = a[i];
    posxor[i].pos = i;
  }

  lli r = 0;
  int t =0;
  int testxor;
  for(int i=0; i<(n-1);i++){
    if(i==0) t= 0;
    else{
      t = a[i-1];
    }
    for(int j=i+1; j<n; j++){
      testxor = a[j]^t;
      if(testxor==0){
        //cout<< j <<" "<< i <<endl;
        r = r + (j-i);
      }
    }
  }
  cout<<r<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(0);
  int cases;
  cin>>cases;
  while(cases){
    cases--;
    solve();
  }
  return 0;
}
