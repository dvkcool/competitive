#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;
  int xmin = 0;
  int ymin = 0;
  int xmax = 200001;
  int ymax = 200001;
  int xfix = -1;
  int yfix = -1;
  int x, y, l, t, r, d;
  for(int i=0; i<n; i++){
    cin>>x>>y>>l>>t>>r>>d;
    x = x + 100000;
    y = y + 100000;
    if(l==0){
      if(x>xmin){
        xmin=x;
      }
    }
    if(r==0){
      if(xmax>x){
        xmax = x;
      }
    }
    if(t==0){
      if(ymax>y){
        ymax = y;
      }
    }
    if(d==0){
      if(ymin<y){
        ymin = y;
      }
    }
    if(l==0 &&(r==0 && (t==0 && d==0))){
      xfix = x;
      yfix = y;
    }
  }

  if(xmin>xmax || ymin >ymax){
    cout<<0<<endl;
    return;
  }
  else{
    if(xfix!=-1){
      if(xmin!=xfix || ymin!=yfix){
        cout<<0<<endl;
        return;
      }
    }
    cout<<1<<" "<<(xmin-100000)<<" "<<(ymin-100000)<<endl;
    return;
  }
}
int main(){
  int n;
  cin>>n;
  while(n>0){
    n--;
    solve();
  }
  return 0;
}
