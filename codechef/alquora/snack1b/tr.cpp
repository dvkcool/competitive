#include<bits/stdc++.h>
using namespace std;

int main(){
// 1 10 20 3
// 3

 int t;
 cin>>t;
 while(t--){

  int n,m,k,l;
  cin>>n>>m>>k>>l;
  int A[n];
  bool B[n];
  for(int i = 0;i < n; i++){
     cin>>A[i];
     B[i] = false;
  }
  //startinng time and jumping it by the time period
  sort(A, A+n);
  int p = 0, cnt = 0, minm = INT_MAX, impp = 0, time;
  for(int t = 0;t < k; t += l){
     if(t != 0){
     //check for index upto which we have element greater
       for(int x = p; x < n; x++){
         if(A[x] < t){
           cnt++;
           p = x+1;
         }else{
           break;
         }
       }
       m += cnt-1;
       //cout<<"m: "<<m<<", cnt : "<<cnt<<endl;

     }
     if(m < minm){
         minm = m;
         impp = p;
         time = t;
       }
       cnt = 0;
  }
  //cout<<"minm: , p, t : "<<minm<<" "<<p<<" "<<time<<endl;
  //check if k or A[impp] comes after t, if yes find difference and subtract that difference from the estimated time
  if(impp != n){
    if((k >= time) && (A[impp] >= time)){
      //cout<<"first condition "<<endl;
      //cout<<k<<" "<<A[impp]<<" "<<time<<endl;
      int diff = A[impp] -time;
      cout<<(minm+1)*l-diff<<endl;
    }else if( k >= time){
      //cout<<"second condition "<<endl;
      int diff = k-time;
      cout<<(minm+1)*l-diff<<endl;
    }
  }
  else{
   //cout<<"third condition "<<endl;
   int diff = k-time;
   cout<<(minm+1)*l - diff<<endl;
  }
 }



 return 0;
}
