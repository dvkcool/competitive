/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
  lli n, a, b, k, temp, rem, q, inc, moves;
  cin>>n>>a>>b>>k;
  lli myScore = 0;
  vector<int> req;
  for(int i=0; i<n; i++){
    cin>>temp;
    rem = temp % (a+b);
    if(rem > 0 && rem<= a){
      myScore++;
    }
    else{
      // I need to do something magical here
      // I need to make skip B j chances such that I win this match
      // rem should be >0 && less than a
      q = (temp) / (a+b);
      if(rem ==0 ) q--;
      inc = q* (a+b);
      inc = temp - inc;
      moves = inc /a ;
      if(inc%a!=0) moves++;
      moves = moves -1; // I already have 1 move
      req.push_back(moves);
    }
  }
  //cout<<myScore<<"\n";
  sort(req.begin(), req.end());
  lli sum = 0;
  for(int i=0; i<req.size(); i++){
    //cout<<req[i]<<" "<<sum<<"\n";
    sum += req[i];
    if(sum > k){
      break;
    }
    myScore++;
  }
  cout<<myScore<<'\n';
  return 0;
}
