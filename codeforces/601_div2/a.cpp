#include <iostream>
using namespace std;
void diff(int d){
  int result = 0;
  if(d>=5){
    result += d/5;
    d = d - ((d/5) * 5);
  }
  if(d>=2){
    result += d/2;
    d = d - ((d/2) * 2);
  }
  if(d>=1){
    result += d;
  }
  cout<<result<<endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, a, b, d;
  cin>>t;
  while(t>0){
    t--;
    cin>>a>>b;
    d = b-a;
    if(a==b){
      cout<<0<<endl;
      continue;
    }
    else if(a<b){
      diff(d);
    }
    else{
      diff(-1*d);
    }
  }
	return 0;
}
