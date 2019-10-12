#include<iostream>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a[100001];
  int t, n, m, x, y, i, j, p, q;
  cin>>t;
  while(t>0){
    t--;
    for(i=0; i<100001; i++){
      a[i] = 0;
    }
    //memset(a, 0, 100001*sizeof(a[0]));
    cin>>n>>m;
    if(m%2==0){
      for(i=0; i<m; i++){
        cin>>x>>y;
      }
      cout<<1<<endl;
      for(i=0; i<n; i++){
        cout<<1<<" ";
      }
      cout<<endl;
    }
    else{
      for(i=0; i<m; i++){
        cin>>x>>y;
        a[x-1]++;
        a[y-1]++;
        p = x-1;
        q = y-1;
      }
      j =-1;
      for(i=0; i<n; i++){
        if(a[i]%2!=0){
          j= i;
          break;
        }
      }
      if(j!=-1){
        cout<<2<<endl;
        for(i=0; i<n; i++){
          if(i!=j){
            cout<<1<<" ";
          }
          else{
            cout<<2<<" ";
          }
        }
        cout<<endl;
      }
      else{
        cout<<3<<endl;
        for(i =0; i<n; i++){
          if(i==p){
            cout<<2<<" ";

          }
          else if(i==q){
            cout<<3<<" ";
          }
          else {
            cout<<1<<" ";
          }

        }
        cout<<endl;
      }

    }
  }

  return 0;
}
