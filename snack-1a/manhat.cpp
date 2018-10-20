#include<iostream>
using namespace std;
int manhatdis(int xa, int xb, int ya, int yb){
  int xt = xa - xb;
  if(xt<0){
    xt = xt * -1;
  }
  int yt = ya - yb;
  if(yt<0){
    yt= yt * -1;
  }
  int total = xt + yt;
  return total;
}
int main(){

 int t;
 cin>>t;
 while(t--){
  int n,m;
  cin>>n>>m;
  int y;
  y = n*m;
  int xr[y];
  int yr[y];
  int c = 0;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      cin>>y;
      if(y==1){
        xr[c]=i;
        yr[c]=j;
        c++;
      }
    }
  }
  int dt[n+m-1];
  for(int i=0; i<(n+m-1); i++){
    dt[i] = 0;
  }
  for(int j=0; j<c; j++){
    for(int k=j+1; k<c; k++){
      int d = manhatdis(xr[j], xr[k], yr[j], yr[k]);
      dt[d]++;
    }
  }
    int d = n+m-2;
   for(int i = 1; i <= d; i++){
     cout<<dt[i]<<" ";
    }
    cout<<endl;


 }
return 0;
}
