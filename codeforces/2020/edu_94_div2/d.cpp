// Jai Mata Di
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void solveTest(){
  int n, temp;
  cin>>n;
  int a[n];
  map<int, vector<int> > place;
  for(int i=0; i<n; i++){
    cin>>temp;
    place[temp].push_back(i);
  }
  vector<pair<int, int> > places;
  // for(int i=0; i<n; i++){
  //   // choosing a i
  //   // o (3000)
  //   auto da = place[a[i]];
  //   for(int j=0; j<da.size(); j++){
  //     for(int k = j+1; k<da.size(); k++){
  //       places.push_back(make_pair(da[j], da[k]));
  //     }
  //   }
  // }
  map<int, int> qbeg, qen;
  for(auto de : place){
    auto da = de.second;
    for(int j=0; j<da.size(); j++){
      for(int k = j+1; k<da.size(); k++){
        // places.push_back(make_pair(da[j], da[k]));
        qbeg[da[j]]++;
        qen[da[k]]++;
      }
    }
  }
  // how many max pairs can I have = 1500 pairs
  // assuming all are equal
  // then we can have atmax like 1500 * 1500 = 2250000 = 10^7
  // 100 test cases so will not pass
  int ans = 0;
  // for(int i=0; i<places.size(); i++){
  //   for(int j=0; j<places.size(); j++){
  //     if(places[j].first > places[i].first && places[j].first < places[i].second && places[j].second > places[i].second){
  //       ans++;
  //       // cout<<places[i].first<<" "<<places[i].second<< " "<<places[j].first<<" "<<places[j].second<< "\n";
  //     }
  //   }
  //   //cout<<places[i].first<<" "<<places[i].second<<"\n";
  // }
  // Lets try to optimise it
  // so basically we need like
  // how many i, k will have j in between
  int pairstart = 0;
  for(int i=0; i<n; i++){
    pairstart -= qen[i];
    // these pairs would have been completed by if
    // j can be anything between these 
    pairstart += qbeg[i];
  }
  cout<<ans<<"\n";
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
