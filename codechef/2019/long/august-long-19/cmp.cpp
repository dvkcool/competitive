#include<iostream>
#include<algorithm>
#include <cstring>
#define lli long long int
using namespace std;
int a[100001];
int flag;
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
  posxor[0].val = a[0];
  posxor[0].pos = 0;
  for(int i=1; i<n; i++){
    a[i] = a[i] ^ a[i-1];
    posxor[i].val = a[i];
    posxor[i].pos = i;
  }

  lli r = 0;
  lli m = 0;
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
  m = r;
  r = 0;

  sort(posxor, posxor+n);
  for(int i=0; i<n; i++){
    if(posxor[i].val==0){
      r = r + posxor[i].pos;
    }
    else{
      break;
    }
  }
  for(int i=0; i<n; i++){
    posxor[i].pos = posxor[i].pos+1;
    //cout<<posxor[i].val<<" "<<i<<endl;
    for(int j=i+1; j<n; j++){
      if(posxor[j].val==posxor[i].val){
        //cout<<posxor[j].pos<<" "<< posxor[i].pos<<endl;
        r = r + (posxor[j].pos - posxor[i].pos);
      }
      else{
        break;
      }
    }

  }
  //cout<<r<<endl;
  if(m!= r){
    cout<<"Break me"<<endl;
    flag =1;
  }
}

int main(){
  n=10;
  flag =0;
  for(int i=1; i<100001; i++){
    for(int b=1; b<100001; b++){
      for(int c =1; c<100001; c++){
        for(int d = 1; d<100001; d++){
          for(int e = 1; e<100001; e++){
            for(int f= 1; f<100001; f++){
              for(int g =1; g<100001; g++){
                for(int h=1; h<100001; h++){
                  for(int j=1; j<10001; j++){
                    for(int k=1; k<10001; k++){
                        a[0]=i;
                        a[1]=b;
                        a[2]=c;
                        a[3]=d;
                        a[4]=e;
                        a[5]=f;a[6]=g;a[7]=h;a[8]=j; a[9]=k;
                        solve();
                        if(flag==1){
                          cout<<i<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<" "<<j<<" "<<k<<endl;
                        }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
