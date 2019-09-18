#include<iostream>
#define MODMAX 1000000007
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  lli a, b, c;
  lli ans, maxa, mina, minb, i, j, sum, sumb;
  /*
  int y[5001][5000];
  for(i =1; i<5001; i++){
    for(j = 1; j<i; j++){
      y[i][j] = (i*i)/(i-j);
      while((y[i][j]-1)*(i-j)<=(i*i)){
        y[i][j]++;
      }
    }
  }
  */
  //prev = 0;
  while(t>0){
    t--;
    cin>>a>>b>>c;
    ans = 0;
    maxa = max(a, c);
    mina = min(a, c);
    ans = ((((((mina-1)*mina)/2)%MODMAX)*(2*mina -1))/3)%MODMAX;
    ans = ans + (((maxa-mina)*(((mina-1)*mina)%MODMAX)/2))%MODMAX;
    minb = min(mina, b);
    sum = 0;
    if(mina > minb){
      sum = ((((((mina-minb-1)*(mina-minb))/2)%MODMAX)*(2*(mina-minb) -1))/3)%MODMAX;
      sum = sum + (((maxa-mina)*(((mina-minb-1)*(mina-minb))%MODMAX)/2))%MODMAX;
    }
    cout<<ans<<" "<<sum<<endl;
    ans = ans - sum -minb;
    if(mina == minb){
      ans++;
    }
    if(ans<0){
      ans = ans + MODMAX;
    }
    for(i= 1; i<minb; i++){
      j = 1;
      //prev = 0;
      while(i-j > 0){
        if(!(y[i][j] <= a || y[i][j] <=c)){
          break;
        }
        if(a>=y[i][j]){
          ans = (ans + (a-y[i][j]+1))%MODMAX;
        }
        if(c>=y[i][j]){
          ans = (ans + (c-y[i][j]+1))%MODMAX;
        }
        j++;
      }
    }
    for(i=minb; i<=b; i++){
      j = 1;
      //prev = 0;
      while(i-j > 0){
        if(!(y[i][j] <= a || y[i][j] <=c)){
          break;
        }
        if(a>=y[i][j] && c>=(i-j+1)){
          ans = (ans + (a-y[i][j]+1))%MODMAX;
        }
        if(c>=y[i][j] && a>=(i-j+1)){
          ans = (ans + (c-y[i][j]+1))%MODMAX;
        }
        j++;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
