#include <iostream>
#include <strings.h>
#define lli long long int
using namespace std;
void swap(string & s, int i, int j){
  char c = s[i];
  s[i] = s[j];
  s[j] = c;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q, right, i, j; string s;
  lli n, k;
  cin>>q;
  while(q>0){
    q--;
    cin>>n>>k>>s;
    right =0;
    for(i= 0; i <n; i++){
      if(s[i]!='0'){
        right = i;
        break;
      }
    }
    // 0 1 2 3 4 5
    // lets say swap 4 with 1 then (3,4) -> (2,3) -> (1,2)
    // so swaps = j - i or right -i
    for(i= right+1; i<n; i++){
      if(s[i]=='0'){
        if(i-right<=k){
          swap(s, i, right);
          k = k - (i-right);
          // next right will be right +1 because we switched it adjacent pair
          right++;
        }
        else if(k>=0){
          for(j = i-k; j>=0 && j<i; j++){
            if(s[j]!='0'){
              swap(s, i, j);
              k = k - (i-j);
              break;
            }
          }
        }
        else{
          // k =0 no moves left
          break;
        }
      }
    }
    cout<<s<<endl;
  }
  return 0;
}
