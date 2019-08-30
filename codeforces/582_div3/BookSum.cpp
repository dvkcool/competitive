#include<iostream>
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  int a[10][11];
  for(int i=0; i<11; i++){
    a[0][i] = 0;
  }
  int sum;
  lli ans;
  for(int i=1; i<10; i++){
    sum = 0;
    for(int j=0; j<10; j++){
      a[i][j] = (i * (j+1))%10;
      sum = sum + a[i][j];
    }
    a[i][10] = sum;
  }
  while(t>0){
    t--;
    lli n, m;
    cin>>n>>m;
    if(n<m){
      cout<<0<<endl;
      continue;
    }
    lli k = n/m;
    int last_digit = m % 10;
    lli complete = k /10;
    ans = complete *a[last_digit][10];
    int left = k%10;
    sum = 0;
    while(left>0){
      ans = ans + a[last_digit][sum];
      left--; sum++;
    }
    cout<<ans<<endl;
  }

  return 0;
}
