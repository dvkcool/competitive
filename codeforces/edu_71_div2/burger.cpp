#include<iostream>
#include<algorithm>
#define lli long long int
using namespace std;
void solve(){
  int b, p, f;
  cin>>b>>p>>f;
  int h, c;
  cin>>h>>c;
  int flag = 0;
  if(h<c){
    flag = 1;
  }
  else{
    int t = h;
    h = c;
    c = t;
  }
  int y = b/2;
  int x = flag==0 ? p : f;
  x = min(x, y);
  //cout<<x<<endl;
  int pr = flag==0 ? f : p;
  pr = min(y-x, pr);
  lli profit = x * c + (pr*h);
  cout<<profit<<endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
  cin>>t;
  while(t>0){
    t--;
    solve();
  }
	return 0;
}
