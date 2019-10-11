#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
    int a[1000001];
    int count[1000001];
    int b[1000001];
    int d[1000001];
    int t, n, i, max_count, tp, j, k, m;
    cin>>t;
    while(t>0){
      t--;
      max_count=0;
      for(i=0; i<1000001; i++){
        a[i] = -1;
        d[i] = 0;
        count[i] = 0;
      }
      cin>>n;
      for(i=0; i<n; i++){
        cin>>tp;
        a[tp] = i;
        d[tp]++;
        b[i] = tp;
      }
      for(i=0; i<n; i++){
        tp = b[i];
        for(k=1; k<=sqrt(tp); k++){
          if(tp%k==0){
            if(tp/k==k){
              if(a[k]>i){
                count[a[k]]++;
              }
            }
            else{
              if(a[k]>i){
                count[a[k]]++;
              }
              m = tp/k;
              if(a[m]>i){
                count[a[m]]++;
              }
            }
          }
        }
      }
      for(int i=0; i<n; i++){
        max_count = max(max_count, count[i]+d[a[i]-1]);
      }
      cout<<max_count<<endl;
    }

  return 0;
}
