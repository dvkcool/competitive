#include <iostream>
#include <strings.h>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <iterator>
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t=1;
  //cin>>t;
  while(t>0){
    t--;
    int n, m, a;
    cin>>n>>m;
    int result[m];
    int count = 0;
    set<int> trees;
    unordered_set<int> valueTrees;
    unordered_set<int> occupied;
    for(int i=0; i<n; i++){
      cin>>a;
      trees.insert(a);
      occupied.insert(a);
    }
    int prev = 1000000001;
    for(int x: trees){
      if(x-1 != prev){
        valueTrees.insert(x);
        if(prev!=1000000001) valueTrees.insert(prev);
      }
      prev = x;
    }
    lli distance = 0;
    // i distance from a tree
    for(int i=1; ; i++){
      for(int x: valueTrees){
        if(occupied.find(x-i)==occupied.end()){
          occupied.insert(x-i);
          result[count++] = x-i;
          distance += i;
        }
        if(count==m){
          break;
        }
        if(occupied.find(x+i)==occupied.end()){
          occupied.insert(x+i);
          result[count++] = x+i;
          distance += i;
        }
        if(count==m){
          break;
        }
      }
      if(count==m){
        break;
      }
    }
    cout<<distance<<endl;
    for(int i=0; i<m; i++){
      cout<<result[i]<<" ";
    }
    cout<<endl;
  }

  return 0;
}
