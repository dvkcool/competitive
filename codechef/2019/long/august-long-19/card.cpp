#include<iostream>
using namespace std;
char s[100001];
int l = 0;
int iflost(){
  int i =0;
  int y = 0;
  for(int i=0; i<l; i++){
    if(s[i]=='1'){
      return 0;
    }
    if(s[i]=='0'){
      y=1;
    }
  }
  if(y==1){
    cout<<"LOSE\n";
    return 1;
  }
  return 0;
}

int ifwon(){
  int i =0;
  for(int i=0; i<l; i++){
    if(s[i]=='0'){
      return 0;
    }
  }
  cout<<"WIN\n";
  return 1;
}
void flip(int i){
  if(i>=0 && i<l){
    if(s[i]=='0'){
      s[i]='1';
    }
    else if(s[i]=='1'){
      s[i]='0';
    }
  }
  //cout<<s<<endl;
}
void solve(){
  cin>>s;
  for(int i=0; i<100001; i++){
    if(s[i]=='\0'){
      l = i;
      break;
    }
  }

  while(1){
    if(iflost()){
      break;
    }
    if(ifwon()){
      break;
    }
    int i = 0;
    for(i=0; i<l; i++){
      if(s[i]=='1'){
        flip(i-1);
        s[i] = 'q';
        flip(i+1);
      }
    }

    //cout<<"hi";
  }
}
int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    solve();
  }
  return 0;
}
