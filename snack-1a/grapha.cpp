#include<bits/stdc++.h>
using namespace std;


bool checkForCoprime(int a , int b){
 int i;
 if(a < b){
  i = a;
 }else{
  i = b;
 }

 for(int k = i; k >= 2;k--){
   if((a%k == 0) && (b%k == 0)){
     return false;
   }
 }


 return true;

}





int main(){

 int t;
 cin>>t;

 while(t--){
  int n;
  cin>>n;
  int  A[n];
  for(int i = 0;i < n;i++){
    cin>>A[i];
  }
  int hashe[n];
  for(int q = 0; q < n;q++){
    hashe[q] = 0;
  }

   bool visited[n];
   for(int a = 0; a < n;a++){
     visited[a] = false;
   }
   int st = 0;
   while(true){
    visited[st] = true;
    hashe[st] = 1;
    for(int l = 0; l < n;l++ ){
      if(hashe[l] != 1){
        if(checkForCoprime(A[st], A[l])){
          hashe[l] = 1;
        }
      }
    }

   int j;
   for( j = 0;j < n; j++){
     if((hashe[j] == 1) && (visited[j] == false)){
      st = j;
      break;
     }
    }
   if(j == n){
    break;
   }
  }

   //dfs(v, 0, visited);
   bool notconnected = false;
   for(int l = 0;l < n;l++){
     if(visited[l] == false){
       //cout<<"index "<<l<<" not connected"<<endl;
       notconnected = true;
       break;
      }
   }

   if(!notconnected){
     cout<<0<<endl;
     for(int k = 0;k < n;k++)
      cout<<A[k]<<" ";

      cout<<endl;

   }else{
     A[0] = 29;
     cout<<1<<endl;
     for(int k = 0;k < n;k++)
     cout<<A[k]<<" ";

     cout<<endl;

   }


 }



return 0;
}
