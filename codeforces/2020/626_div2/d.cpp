/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
void setResult(int *res, int count[][32], int a[][32], int i, int n){
  stack<int> pos;
  stack<int> carry;
  stack<int> num;
  pos.push(0);
  carry.push(0);
  num.push(1);// 1 such combination
  int p, c, x, y, np, tp;
  while(!pos.empty()){
    p = pos.top(); pos.pop();
    c = carry.top(); carry.pop();
    np = num.top(); num.pop();
    if(p<=30){
      // How many places have 1 in this places
      x = count[n-1][p];
      if(i>0) x -= count[i-1][p];

      y = n- i; // How many numbers are ahead in array of me
      if(c==0){
        // If carry is 0 it only depends on the numbers to take care
        // it can go to only c =1 or c=0
        // for c = 1 => if a[i][p] == 1
        if(a[i][p] ==1 && x >=1 ){
          // with how many numbers  will I get sum 0, c =1
          pos.push(p+1);
          carry.push(1);
          num.push(np*x);
        }
        if(y-x > 0 && a[i][p] ==1){
          // Number of places without 1, sum = 1, c =0
          tp = y-x;
          tp = tp * np;
          if(tp%2!=0){
            res[p] = res[p] ^ 1;
          }
          pos.push(p+1);
          carry.push(0);
          num.push(tp);
        }
        if(a[i][p]==0 && x>0){
          tp = x * np;
          if(tp%2 != 0){
            res[p] = res[p] ^ 1;
          }
          pos.push(p+1);
          carry.push(0);
          num.push(tp);
        }
        else if(y-x> 0 && a[i][p] ==0){
          tp = (y-x) * np;
          pos.push(p+1);
          carry.push(0);
          num.push(tp);
        }
      }
      else{
        if(a[i][p] ==1 && x >=1 ){
          // with how many numbers  will I get sum 0
          // but c = 1; so we will get a sum 1
          tp = np*x;
          if(tp%2 !=0){
            res[p] = res[p] ^ 1;
          }
          pos.push(p+1);
          carry.push(1);
          num.push(np*x);
        }
        if(y-x > 0 && a[i][p] ==1){
          // Number of places without 1
          // this will lead to sum = 0 as c= 1;
          tp = y-x;
          tp = tp * np;
          pos.push(p+1);
          carry.push(0);
          num.push(tp);
        }
        if(a[i][p]==0 && x>0){
          // this will lead to sum = 0, c= 1;
          tp = x * np;
          pos.push(p+1);
          carry.push(1);
          num.push(tp);
        }
        else if(y-x> 0 && a[i][p] ==0){
          // both are 0 but c= 1; hence sum = 1; c = 0
          tp = (y-x) * np;
          if(tp %2 !=0){
            res[p] = res[p] ^ 1;
          }
          pos.push(p+1);
          carry.push(0);
          num.push(tp);
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);  cout.tie(0);
  int n;
  cin>>n;
  int a[n][32];
  memset(a, 0, sizeof(a));
  int temp;
  int st;
  for(int i=0; i<n; i++){
    cin>>temp;
    st = 1;
    for(int j=0; j<32; j++){
      if(temp&st){
        a[i][j]++;
      }
      st = st <<1;
    }
  }
  int res[32] = {0};
  int count[n][32];
  for(int i=0; i<32; i++){
    count[0][i] = a[0][i];
  }
  for(int i=1; i<n; i++){
    for(int j=0; j<32; j++){
      count[i][j] += (a[i][j] + count[i-1][j]);
    }
  }
  for(int i=0; i<n; i++){
    // set result bit corresponding to a[i]
    setResult(res, count, a, i, n);
  }
  lli r = 0;
  st = 1;
  for(int i=0; i<32; i++){
    if(res[i]){
      r += st;
    }
    st = st<<1;
  }
  cout<<r<<"\n";
  return 0;
}
