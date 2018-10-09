#include <iostream>
#include <vector>

using namespace std;
int c[10];
int sumdigit(int n){
  int r =0;
  while(n>0){
    r = r + n%10;
    n = n/10;
  }
  return r;
}
void checkmin(int n, int d){
  vector<int> v;
  int cn = 0;
  while(true){
    int sum = sumdigit(n);
    int st = 1;
    while(sum>=10){
      sum = sumdigit(sum);
      st++;
    }
    if(sum==1){
      cn = cn+st;
      cout<<"1 "<<cn<<"\n";
      return;
    }
    if(c[sum]==0){
      c[sum] = cn+st;
      v.push_back(sum);
    }
    if(v.size()>1 && sum==v.front()){
      int min = 9;
      for(int i=0; i<10; i++){
        if(c[i]!=0 && min>i){
          min = i;
        }
      }
      cout<<min<<" "<<c[min]<<"\n";
      return;
    }
    n = n +d;
    cn++;
  }
}
int main(){
  int cases, n, d, i;
  cin>>cases;
  for(i=0; i<cases; i++){
    cin>>n>>d;
    for(int j=0; j<10; j++){
      c[j]=0;
    }
    checkmin(n, d);
  }
  return 0;

}
