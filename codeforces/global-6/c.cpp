#include <iostream>
#include <strings.h>
#define lli long long int
using namespace std;
int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
 }
  int lcm(int a, int b)
 {
    return (a*b)/gcd(a, b);
 }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
  int r, c;
  cin>>r>>c;
  if(r==1 && c==1){
    cout<<"0"<<endl;
  }
  else if(r==1||c==1){
    int m =2;
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        cout<< m<<" ";
        m++;
      }
      cout<<endl;
    }
  }
  else{
    lli res[r][c];
    int m = r+1;
    int x = min(r, c);
    if(x==r){
      for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
          res[i][j] = lcm((i+1),(r+j+1));
          m++;
        }
      }
    }
    else{
      for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
          res[j][i] = lcm((i+1),(c+j+1));
          m++;
        }
      }
    }

    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        cout<<res[i][j]<<" ";
      }
      cout<<endl;
    }
  }
	return 0;
}
