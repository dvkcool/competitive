#include<bits/stdc++.h>
#define SIZEMAX 100001
#define TWICEMAX 200001
#define MODMAX 1000000007
#define lli long long int
using namespace std;
//char a[SIZEMAX];
//char b[SIZEMAX];
//char c[SIZEMAX];
lli powten[TWICEMAX];
int l, re;
/*
int carry = 0;
int carryp = 0;
int u;
int flag = 0;
int l, re;
int calcf(int i){
  int maxl = 0;
  char *q;
  int r = 0;
  if(i==0){
    maxl = l;
    q = a;
  }
  else{
    maxl =  re;
    q = b;
  }
  for(int j=0; j<maxl; j++){
    r = r + ((q[j] - '0') * powten[maxl-j-1])%MODMAX;
    if(r>=MODMAX){
      r = r-MODMAX;
    }
    while(j<maxl){
      if(q[j+1]==q[j]){
        j++;
      }
      else{
        break;
      }
    }
  }
  return r;
}
void addcarry(){
  if(carryp <0){
    flag = 1;
    return;
  }
  u = (a[carryp] - '0') + carry;
  a[carryp] = '0' + (u%10);
  if(u>=10){
    carry = u/10;
    carryp--;
    addcarry();
  }
}
void adcarry(){
  if(carryp <0){
    flag = 1;
    return;
  }
  u = (b[carryp] - '0') + carry;
  b[carryp] = '0' + (u%10);
  if(u>=10){
    carry = u/10;
    carryp--;
    adcarry();
  }
}
void subtcarry(){
  if(flag==1){
    return;
  }
  if(b[0]=='0'){
    flag = 1;
    return;
  }
  u = (b[carryp] - '0') - carry;
  if(u<0){
    b[carryp] = '0' + (u+10);
    carryp--;
    if(b[0]=='0'){
      flag = 1;
      return;
    }
    subtcarry();
  }
  else{
    b[carryp] = '0' + u;
  }
  if(b[0]=='0'){
    flag = 1;
    return;
  }
}
int calcleft(int l){
  lli r = 0;
  while(flag!=1){
    r = r + calcf(0)%MODMAX;
    if(r>=MODMAX){
      r =r - MODMAX;
    }
    carry = 1;
    carryp = l-1;
    addcarry();
  }
  return r;
}
int calcright(int re){
  lli r = 0;
  flag = 0;
  //cout<<"called me"<<endl;
  while(flag!=1){
    //cout<<"enter"<<endl;
    r = r + calcf(1)%MODMAX;
    if(r>=MODMAX){
      r =r - MODMAX;
    }
    carry = 1;
    carryp = re-1;
    subtcarry();
  }
  return r;
}
int calcrlf(int re){
  lli r = 0;
  carry = 1;
  carryp = re-1;
  adcarry();
  while(flag!=1){
    r = r + calcf(1)%MODMAX;
    if(r>=MODMAX){
      r =r - MODMAX;
    }
    carry = 1;
    carryp = re-1;
    adcarry();
  }
  return r;
}
int stackleft(string s, int result){
  if(s.length()>=l){
    return 1;
  }
  if(same==1){
    // min - known
    // choose among options
  }

}
*/
int calcf(string s, int p){
  lli r = 0;
  for(int j=0; j<p; j++){
    r = r + ((s[j] - '0') * powten[p-j-1])%MODMAX;
    if(r>=MODMAX){
      r = r-MODMAX;
    }
    while(j<p){
      if(s[j+1]==s[j]){
        j++;
      }
      else{
        break;
      }
    }
  }
  return r;
}
string s;
int calc(lli m, lli n, int y){
  lli r = 0;
  for(; m<=n; m++){
    s = to_string(m);
    r =  r + calcf(s, y);
    if(r>=MODMAX){
      r = r - MODMAX;
    }
  }
  return r;
}
int cald(lli m, lli n){
  lli r = 0;
  for(; m<=n; m++){
    s = to_string(m);
    r =  r + calcf(s, s.length());
    if(r>=MODMAX){
      r = r - MODMAX;
    }
  }
  return r;
}
void solve(){
  lli a, b;
  cin>>l;
  cin>>a;
  cin>>re;
  cin>>b;
  lli r = 0;
  r = cald(a, b);
  cout<<r<<endl;
  r = 0;
  if(l==re){
    // equal check
    r = calc(a, b, l);
    if(r<0){
      r = r +MODMAX;
    }
  }
  else{
    r =  calc(a, pow(10, l)-1, l);
    //cout<<r<<endl;
    r =  r + calc(pow(10, re-1), b, re);
    r = r%MODMAX;
    //cout<<r<<endl;
    for(int i=l+1; i<re; i++){
      r = r + (45 * (powten[2*i-2] + (8* powten[2*i-4])%MODMAX)%MODMAX)%MODMAX;
      r = r %MODMAX;
      if(i>=3){
        int temp = powten[i-2] - 1;
        if(temp<0){
          temp = temp + MODMAX;
        }
        r = r + (((45 * (9 * powten[i-3])%MODMAX)%MODMAX)*temp)%MODMAX;
        r = r %MODMAX;
      }
    }
  }
  cout<<r<<endl;
}
int main(){
  int t;
  cin>>t;
  powten[0] = 1;
  for(int i=1; i<TWICEMAX; i++){
    powten[i] = (powten[i-1] * 10)%MODMAX;
  }
  while(t>0){
    solve();
    t--;
  }
  return 0;
}
