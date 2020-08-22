// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int h, w, cx, cy, dx, dy;
bool block[1001][1001];
lli countM[1001][1001];
bool vis[1001][1001];
lli minSteps(int x, int y){
  if(x==dx && y==dy) return 0;
  else if(x>h || y>w) return INT_MAX;
  else if(x<1 || y<1) return INT_MAX;
  else if(!block[x][y]) return INT_MAX;
  else if(countM[x][y] != -1) return countM[x][y];
  lli ans = INT_MAX;
  vis[x][y] = 1;
  //cout<<"Entry "<<x<<" "<<y<<"\n";
  // horizontally or vertically
  bool e = 0;
  if(!vis[x-1][y]){vis[x-1][y]=1;ans = min(ans, minSteps(x-1, y));vis[x-1][y]=0;}
  if(!vis[x+1][y]){vis[x+1][y]=1;ans = min(ans, minSteps(x+1, y));vis[x+1][y]=0;}
  if(!vis[x][y+1]){vis[x][y+1]=1;ans = min(ans, minSteps(x, y+1));vis[x][y+1]=0;}
  if(!vis[x][y-1]){vis[x][y-1]=1;ans = min(ans, minSteps(x, y-1));vis[x][y-1]=0;}
  // // Use magic
  // // if at x,y leftmost = x-2, r = x+2
  // // top = y-2, b = y+2
  for(int i=x-2; i<=x+2; i++){
    for(int j=y-2; j<=y+2; j++){
      if(i!=x && j!=y && i>0 && i<=h && j>0 && j<=w && !vis[i][j]){
        //cout<<x<<" "<<y<<" "<<i<<" "<<j<<" \n";
        vis[i][j] = 1;
        ans= min(ans, 1 + minSteps(i, j));
        vis[i][j] = 0;
        //cout<<ans<<"\n";
      }
    }
  }

  countM[x][y] = ans;
  return ans;
}
void solveTest(){
  cin>>h>>w>>cx>>cy>>dx>>dy;
  char c;
  for(int i=1; i<=h; i++){
    for(int j=1; j<=w; j++){
      cin>>c;
      block[i][j] = (c=='.');
      countM[i][j] = -1;
      vis[i][j] = 0;
    }
  }
  cout<<(minSteps(cx, cy)>= INT_MAX ? -1 : minSteps(cx, cy))<<"\n";
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1, i=1;
  //cin>>t;//Comment if only one test case
  while(i<=t){
    //cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
