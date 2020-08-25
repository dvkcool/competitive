// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
vector<pair<int, int> > weapon;
int result[2][2];int j = 0;
void maxweiht(int *res, int *capt){
  int cap = *capt;
  // cout<<cap<<"\n";
  int q = cap/weapon[0].first;
  int r = min(q, weapon[0].second);
  cap -= weapon[0].first * r;
  // weapon[0].second -= r;
  *res = *res + r;
  result[j][0] = r;
  // cout<<r<<" "<<cap<<"\n";
  q = cap/weapon[1].first;
   r = min(q, weapon[1].second);
  cap -= weapon[1].first * r;
  // weapon[1].second -= r;
  *res = *res + r;
  result[j][1] = r;
  // cout<<r<<" "<<cap<<"\n";
  *capt = cap;
}
void maxweight(int *res, int *capt){
  int cap = *capt;
  // cout<<cap<<"\n";
  int q = cap/weapon[0].first;
  int r = min(q, weapon[0].second);
  cap -= weapon[0].first * r;
  weapon[0].second -= r;
  *res = *res + r;
  result[j][0] = r;
  // cout<<r<<" "<<cap<<"\n";
  q = cap/weapon[1].first;
   r = min(q, weapon[1].second);
  cap -= weapon[1].first * r;
  weapon[1].second -= r;
  *res = *res + r;
  result[j][1] = r;
  // cout<<r<<" "<<cap<<"\n";
  *capt = cap;
}

void solveTest(){
  int p, f;
  cin>>p>>f;
  int x, y;
  cin>>x>>y;
  int s, w;
  cin>>s>> w;
  weapon.clear();
  pair<int, int> sword = make_pair(s, x);
  pair<int, int> axe = make_pair(w, y);
  weapon.push_back(sword);
  weapon.push_back(axe);
  int res = 0;
  sort(weapon.begin(), weapon.end());
  int we = f+p;
  j = 0;
  int resq = 0;
  maxweiht(&resq, &we);
  j = 0;
  maxweight(&res, &f);
  j++;
  maxweight(&res, &p);int ratio, extra;

  // while(1){
  //   ratio = weapon[1].first- f + weapon[0].first - 1;
  //   ratio = ratio / weapon[0].first;
  //   f = 0;
  //   // NUmber of weapons to be exchanged for one hea
  //   if(result[0][0] >= ratio){
  //     extra = weapon[1].first - p+ weapon[0].first -1;
  //     p = 0;
  //     extra = extra / weapon[0].first;
  //     if(extra > ratio){
  //       res += (extra - ratio);
  //     }
  //     else{
  //       break;
  //     }
  //   }
  //   else{
  //     break;
  //   }
  // }
  if(we ==0 && f!=0 && p!=0)
  cout<<res<<"\n";
  else cout<<resq<<"\n";
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, i=1;
  cin>>t;//Comment if only one test case
  while(i<=t){
    //cout<<"Case #"<<i<<": ";
    solveTest();
    i++;
  }
  return 0;
}
