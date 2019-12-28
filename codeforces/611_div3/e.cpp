#include <iostream>
#include <strings.h>
#include <algorithm>
#include <vector>
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t=1;
  //cin>>t;
  while(t>0){
    t--;
    int n, t;
    cin>>n;
    int vacant[200005]={0};
    for(int i=0; i<n; i++){
      cin>>t;
      vacant[t]++;
    }
    vector<int> threePlaces;
    vector<int> twoPlaces;
    vector<int> singlePlaces;
    for(int i=1; i<=n; i++){
      if(vacant[i]!=0 && vacant[i+1]!=0 && vacant[i+2]!=0){
        threePlaces.push_back(i);
        i = i+2;
      }
      else if(vacant[i]!=0 && vacant[i+1]!=0){
        twoPlaces.push_back(i);
        i++;
      }
      else if(vacant[i]!=0){
        singlePlaces.push_back(i);
      }
    }
    int max = 0;
    for(int i=1; i<=n; i++){
      if(vacant[i]==1){
        continue;
      }
      if(vacant[i-1]==0 && vacant[i]>1){
        vacant[i-1]++;
        vacant[i]--;
      }
      if(vacant[i+1]==0 && vacant[i]>1){
        vacant[i+1]++;
        vacant[i]--;
      }
    }
    for(int i=0; i<n+3; i++){
      if(vacant[i]!=0 ){
        max++;
      }
    }
    cout<<threePlaces.size()+twoPlaces.size()+singlePlaces.size()<<" ";
    cout<<max<<endl;

  }

  return 0;
}
