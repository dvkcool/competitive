#include<iostream>
#define lli long long int
using namespace std;
int xnor(int n, int a[], int b[], int l, lli av, lli bv){
  if(n==1){
    return av;
  }
  else if(n==2){
    return bv;
  }
  else if(n==3){
    lli ans = 0;
    lli pow2 = 1;
    for(int i =0; i<l; i++){
      if(a[i] == b[i]){
        ans = ans + pow2;
      }
      pow2 = pow2 * 2;
    }
    return ans;
  }
  else{
    if(n%3==1){
      lli ans = 0;
      lli pow2 = 1;
      for(int i =0; i<l; i++){
        if(a[i] == 1){
          ans = ans + pow2;
        }
        pow2 = pow2 * 2;
      }
      return ans;
    }
    else if(n%3==2){
      lli ans = 0;
      lli pow2 = 1;
      for(int i =0; i<l; i++){
        if(b[i]== 1){
          ans = ans + pow2;
        }
        pow2 = pow2 * 2;
      }
      return ans;
    }
    else{
      lli ans = 0;
      lli pow2 = 1;
      for(int i =0; i<l; i++){
        if(a[i] == b[i] && (b[i]==1 || b[i]==0)){
          ans = ans + pow2;
        }
        pow2 = pow2 * 2;
      }
      return ans;
    }

  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, lenA, lenB;
  lli a, b, n, c, d, xorval, xnorval;
  int binNumA[41], binNumB[41];
  cin>>t;
  while(t>0){
    t--;
    cin>>a>>b>>n;
    c= a;
    d = b;
    lenB = 0; lenA = 0;
    while(c>0){
      binNumA[lenA++] = c%2;
      c = c/2;
    }
    while(d>0){
      binNumB[lenB++] = d%2;
      d = d/2;
    }
    while(lenA != max(lenA, lenB)){
      binNumA[lenA++]= 0;
    }
    while(lenB != max(lenA, lenB)){
      binNumB[lenB++]= 0;
    }
    if(n%3==1){
      xorval = a;
    }
    else if(n%3==2){
      xorval = b;
    }
    else{
      xorval = a ^ b;
    }
    xnorval = xnor(n, binNumA, binNumB, lenA, a, b);
    cout<<max(xorval, xnorval)<<endl;
  }
}
