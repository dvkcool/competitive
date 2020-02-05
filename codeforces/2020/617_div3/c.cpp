/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
  int t, n, x, y;
  cin>>t;
  while(t--){
    cin>>n;
    string s;
    cin>>s;
    int minLen = n +1;
    int r=0, rf=0;
    x = 0, y = 0;
    map<pair<int, int> , int > place;
    place[make_pair(x, y)] = 0;
    for(int i=0; i<n; i++){
      switch(s[i]){
        case 'U':
          y++;
          break;
        case 'D':
            y--;
            break;
        case 'L':
            x--;
            break;
        case 'R':
            x++;
            break;
      }
      if(place.find(make_pair(x, y)) != place.end()){
        // I have a previous occurence of same
        int q = place[make_pair(x, y)];
        if(i-q < minLen){
          minLen = i- q;
          r = q+1;
          rf = i+1;
        }
      }
      place[make_pair(x, y)] = i+1;
    }
    if(minLen == n+1){
      cout<<"-1\n";
    }
    else{
      cout<<r<<" "<<rf<<"\n";
    }
  }
  return 0;
}
