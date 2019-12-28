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
    int n;
    cin>>n;
    int a[n];int count[n+1];
    for(int i=0; i<n; i++){
      cin>>a[i]; count[i] = 0;
    }
    count[n] =0;
    for(int i=0; i<n; i++){
      count[a[i]]++;
    }
    vector<int> problematic;
    vector<int> safe;
    vector<int> places;
    for(int i=0; i<n; i++){
      if(count[i+1]==0 && a[i]==0){
        problematic.push_back(i);
      }
      else if(count[i+1]==0){
        safe.push_back(i);
      }
      else if(a[i]==0){
        places.push_back(i);
      }
    }
    if(problematic.size() == 1){
      a[places[0]] = problematic[0] + 1;
      a[problematic[0]] = safe[0] +1;
      for(int i=1; i<safe.size(); i++){
        a[places[i]] = safe[i]+1;
      }
    }
    else if(problematic.size()>1){
      for(int i=0; i<problematic.size() -1; i++){
        a[problematic[i]] = problematic[i+1] +1;
      }
      a[problematic[problematic.size()-1]] = problematic[0]+1;
      for(int i=0; i<safe.size(); i++){
        a[places[i]] = safe[i]+1;
      }
    }
    else{
      for(int i=0; i<safe.size(); i++){
        a[places[i]] = safe[i]+1;
      }
    }
    for(int i=0; i<n; i++){
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }

  return 0;
}
