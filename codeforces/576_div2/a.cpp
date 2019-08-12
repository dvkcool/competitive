#include<iostream>
using namespace std;
int checklower(int a[], int i, int x, int n){
  int e = 0;
  for(int j= i-1; j>=0; j--){
    e++;
    if(e>x){
      break;
    }
    if(a[j]<a[i]){
      return 0;
    }
  }
  return 1;
}
int checkupper(int a[], int i, int x, int n){
  int e = 0;
  for(int j= i+1; j<n; j++){
    e++;
    if(e>x){
      break;
    }
    if(a[j]<a[i]){
      return 0;
    }
  }
  return 1;
}
int main(){
  int n, x, y;
  cin>>n>>x>>y;
  int r = 0;
  int xinc = 0;
  int a[n];
  /*
  int b[n];
  int c[n];
  */
  for(int i=0; i<n; i++){
    cin>>a[i];
    //b[i] = 0;
    //c[i] = 0;
  }
  for(int i=0; i<n; i++){
    if(checklower(a, i, x, n) && checkupper(a, i, y, n)){
      cout<<(i+1)<<endl;
      return 0;
    }
  }
  /*
  for(int i=1; i<(n-1); i++){
    //cout<<xinc<<" "<<i<<endl;

    if(a[i-1]>a[i]){
      xinc++;
    }
    else if(a[i-1]<a[i]){
      xinc = 0;
    }
//cout<<xinc<<" s "<<i<<endl;
    if(a[i-1]>a[i] && a[i]<a[i+1]){
      //check for prev x and next y
      if(xinc>=x || xinc ==i){
        //cout<<i<<"this"<<xinc<<endl;
        xinc = 0;
        for(int j=i+1; j<n; j++){
          if(a[j]>a[i]){
            xinc++;
          }
          else{
            break;
          }
          // another check
          if(xinc>=y){
            break;
          }
        }
        if(xinc>=y || xinc==(n-1-i)){
          cout<<(i+1)<<endl;
          return 0;
        }
      }
      xinc = 0;
    }
    //cout<<xinc<<" "<<i<<endl;
  }
  */
  cout<<n<<endl;
  /*
  for(int i=1; i<n; i++){
    b[i]= b[i-1];
    if(a[i]<=a[i-1]){
      b[i]++;
    }
    else{
      b[i] = 0;
    }
  }
  for(int i=n-2; i>=0; i++){
    c[i] = c[i+1];
    if(a[i]<=a[i+1]){
      c[i]++;
    }
    else{
      c[i] = 0;
    }
  }
  for(int i=1; i<(n-1); i++){
    if(b[i]>=x && c[i]>=y){
      b[i] = 0;
      c[i] = 0;
      for(int j = i-1; j>=0; j++){
        if(a[i]<a[j]){
          b[i]++;
        }
        else{
          break;
        }
        if(b[i]>=x) break;
      }
      for(int j= i+1; j<n; j++){
        if(a[j] >a[i]){
          c[i]++;
        }
        else{
          break;
        }
        if(c[i]>=x) break;
      }
      if(b[i]>=x && c[i]>=y){
        cout<<(i+1)<<endl;
        return 0;
      }
    }
    else if(b[i]>=x && )
  }
  */
  return 0;
}
