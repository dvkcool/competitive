#include<bits/stdc++.h>
#define SIZEMAX 100001
#define TWICEMAX 200001
#define MODMAX 1000000007
#define lli long long int
using namespace std;
char a[SIZEMAX];
char b[SIZEMAX];
int ai[SIZEMAX];
int bi[SIZEMAX];
string s;
//char c[SIZEMAX];
lli powten[TWICEMAX];
int l, re, p, q, z, y;
void convertToInt(int i){
  char *q;
  int *e;
  int maxl = 0;
  if(i==0){
    q = a;
    e = ai;
    maxl = l;
  }
  else{
    q = b;
    e = bi;
    maxl = re;
  }
  for(i=0; i<maxl; i++){
    e[i] = (q[i] - '0');
  }
}
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
int calclessum(int i){
  // Choosing variables
  int *e;
  int maxl = 0;
  lli r = 0;
  if(i==0){
    e = ai;
    maxl = l;
  }
  else{
    e = bi;
    maxl = re;
  }
  // Variable done


  for(i=0; i<maxl; i++){

    // p = ahead of i, with at pos = e[i]

    p = 0;
    for(int j=i+1; j<maxl; j++){
      if(j==maxl-1){
        p = p + e[j]+1;
        if(p>=MODMAX){
          p = p - MODMAX;
        }
        continue;
      }
      if(e[j]==0){
        continue;
      }
      p = p + (e[j]* powten[maxl-j-1])%MODMAX;
      if(p>=MODMAX){
        p = p - MODMAX;
      }
    }
    if(maxl==1 && p==0){
      p=1;
    }



    // z = before of i, with at pos > e[i]

    z = 0;
    for(int j=i-2; j>=0; j--){
      if(e[j]==0){
        continue;
      }
      if(j==0 && e[j]==1){
        continue;
      }
      if(j==0){
        z = z + ((((e[j]-1)* powten[i-j-2])%MODMAX)*9)%MODMAX;
        if(z>=MODMAX){
          z = z - MODMAX;
        }
        continue;
      }
      z = z + (((e[j]* powten[i-j-2])%MODMAX)*9)%MODMAX;
      if(z>=MODMAX){
        z = z - MODMAX;
      }
    }


    // y : before of i, with at pos < e[i]
    y = 0;
    for(int j=i-2; j>=0; j--){
      if(j==0){
        y = y + ((((e[j]-1)* powten[i-j-2])%MODMAX)*9)%MODMAX;
        if(y>=MODMAX){
          y = y - MODMAX;
        }
        continue;
      }
      y = y + ((((e[j]+1)* powten[i-j-2])%MODMAX)*9)%MODMAX;
      if(y>=MODMAX){
        y = y - MODMAX;
      }
    }
    if(i==0 && y==0){
      y= 1;
    }

    // Choosing actual digit
    for(int j=1; j<=9; j++){
      q = 0;
      if(j>e[i]){
        if(i-1>0){
          if(e[i-1]<=j && e[i-1]!=0){
              q = e[i-1];
          }
          else if(e[i-1]>j){
              q = e[i-1] -1;
          }
        }
        if(i-1==0){
          if(e[i-1]<=j && e[i-1]!=0){
              q = e[i-1]-1;
          }
          else if(e[i-1]>j){
              q = e[i-1] -2;
          }
        }
         r = r + (((((z+q)%MODMAX)*j)%MODMAX)*powten[2*maxl - (2*i)-2])%MODMAX;
         if(r>=MODMAX){
           r = r - MODMAX;
         }
      }
      else if(j<e[i]){
        if(i-1>0){
          if(e[i-1]<j){
              q = e[i-1]+1;
          }
          else if(e[i-1]>=j){
              q = e[i-1];
          }
        }
        if(i-1==0){
          if(e[i-1]<j){
              q = e[i-1];
          }
          else if(e[i-1]>=j){
              q = e[i-1]-1;
          }
        }
        if(i+1==maxl){
          r = r + (((((z+q)%MODMAX)*j)%MODMAX)*powten[2*maxl - (2*i)-2])%MODMAX;
          if(r>=MODMAX){
            r = r - MODMAX;
          }
          continue;
        }
        lli pe = (((j*powten[2*maxl - (2*i)-2])%MODMAX)*((y+q)%MODMAX))%MODMAX;
        r = r + pe;
        if(r>=MODMAX){
          r = r - MODMAX;
        }
      }
      else{
        if(i+1==maxl){
          if(i-1>0){
            if(e[i-1]<j){
                q = e[i-1]+1;
            }
            else if(e[i-1]>=j){
                q = e[i-1];
            }
          }
          if(i-1==0){
            if(e[i-1]<j){
                q = e[i-1];
            }
            else if(e[i-1]>=j){
                q = e[i-1]-1;
            }
          }
        }
        else{
          if(i-1>0){
            if(e[i-1]<=j){
                q = e[i-1];
            }
            else if(e[i-1]>j){
                q = e[i-1]-1;
            }
          }
          if(i-1==0){
            if(e[i-1]<=j){
                q = e[i-1]-1;
            }
            else if(e[i-1]>j){
                q = e[i-1]-2;
            }
          }
        }
        lli pe = (((j*powten[2*maxl - (2*i)-2])%MODMAX)*((z+q)%MODMAX))%MODMAX;
        //cout<<"j: "<<j<<" "<<pe<<endl;
        r = r + pe;
        r = r % MODMAX;
        //cout<<r<<endl;
        if(i-1>=0 && j==e[i-1]){
          //cout<<"r: "<<r<<" i: "<<i<<" j: "<<j<<" p: "<<p<<" q: "<<q<<" z: "<<z<<" y: "<<y<<endl;

          continue;
        }
        r = r + (((p*j)%MODMAX)* powten[maxl-i-1])%MODMAX;
        if(r>=MODMAX){
          r = r - MODMAX;
        }


      }
      //cout<<"r: "<<r<<" i: "<<i<<" j: "<<j<<" p: "<<p<<" q: "<<q<<" z: "<<z<<" y: "<<y<<endl;
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
int getint(int i){
  // Choosing variables
  int *e;
  int maxl = 0;
  int r = 0;
  if(i==0){
    e = ai;
    maxl = l;
  }
  else{
    e = bi;
    maxl = re;
  }
  for(i=0; i<maxl; i++){
    r = r*10 + e[i];
  }
  return r;
}

void solvesmart(){
  int da, db;
  cin>>l;
  cin>>a;
  cin>>re;
  cin>>b;
  convertToInt(0);
  convertToInt(1);
  lli r = 0;
  if(re<=3){
    da = getint(0);
    db = getint(1);
    lli r = 0;
    r = cald(da, db);
    cout<<r<<endl;
    return;
  }
  //cout<<calclessum(1)<<endl;
  //cout<<calclessum(0)<<endl;
  if(l==re){
    //cout<<calclessum(1)<<endl;
    //cout<<calclessum(0)<<endl;
    r = calclessum(1) - calclessum(0);
    if(r<0){
      r = r + MODMAX;
    }
    r = r + calcf(a, l);
    r = r % MODMAX;
    cout<<r<<endl;
    return;
  }
  for(int i=l; i<re; i++){
    r = r + (45 * (powten[2*i-2]%MODMAX))%MODMAX;
    r = r %MODMAX;
    if(i>=2){
      r = r + (45 * (8* powten[2*i-4])%MODMAX)%MODMAX;
      r = r %MODMAX;
    }
    if(i>=3){
      int temp = powten[i-2] - 1;
      if(temp<0){
        temp = temp + MODMAX;
      }
      r = r + (((45 * (9 * powten[i-3])%MODMAX)%MODMAX)*temp)%MODMAX;
      r = r %MODMAX;
    }
  }
  //cout<<r<<endl;
  r = r - calclessum(0);
  //cout<<r<<endl;
  if(r<0){
    r = r + MODMAX;
  }
  r = r%MODMAX;
  //cout<<calcf(b, re)<<endl;
  r = (r + calclessum(1))%MODMAX;
  r = r + calcf(a, l);
  //cout<<r<<endl;

  r = r % MODMAX;
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
    solvesmart();
    t--;
  }
  return 0;
}
