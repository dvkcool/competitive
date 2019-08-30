#include<iostream>
#include <set>
#include <iterator>
#include <vector>
#include <algorithm>
#define lli long long int
using namespace std;
/*
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin>>n>>k;
  int a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a, a+n);
  int sameMax = 0;
  int same = 0;
  int sameIndex =0;
  for(int i=0; i<n; i++){
    same = 1;
    int j;
    for(j=i+1; j<n; j++){
      if(a[i]==a[j]){
        same++;
      }
      else{
        break;
      }
    }
    i =j-1;
    if(same>sameMax){
      sameMax = same;
      sameIndex =  i;
    }
  }
  if(sameMax>=k){
    cout<<0<<endl;
    return 0;
  }
  else{
    int minTrans = 100000000;
    for(int i=0; i<n; i++){
      int
    }
  }


  return 0;
}
*/
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin>>n>>k;
  int a[n][20];
  int count[n];
  int maxCount = 0;
  for(int i=0; i<n; i++){
    cin>>a[i][0];
    count[i] = 0;
    int j =0;
    while(a[i][j]>0){
      a[i][j+1] = a[i][j] /2;
      j++;
      count[i]++;
    }
    maxCount += count[i];
  }
  set<int> doneNum;
  for(int i=0; i<n; i++){
    int p =count[i];
    while(p>=0){
      int t = a[i][p];
      if(doneNum.count(t)==0){
        //cout<<"hi "<<t<<endl;
        doneNum.insert(t);
        int r = 0;
        vector<int> v;
        for(int j=0; j<n; j++){
          for(int l=0; l<=count[j]; l++){
            if(a[j][l]==t){
              v.push_back(l);
              break;
            }
          }
        }
        if(v.size()<k){
          continue;
        }
        sort(v.begin(), v.end());
        int q = 0;
        vector<int>::iterator x;
        int f =0;
        for( x = v.begin(); x != v.end(); ++x){
          if(q>=k){
            break;
          }
          f++;
          q++;
          r = r + *x;
        }
        //cout<<r<<" r:"<<endl;
        if(r<maxCount && f!=0){
          maxCount = r;
        }

      }
      p--;
    }
  }
  cout<<maxCount<<endl;
  return 0;
}
