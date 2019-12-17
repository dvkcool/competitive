#include <iostream>
#include <strings.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); bool done;
  int q, n, k, oneCount;
  cin>>q;
  while(q>0){
    q--;
    string s, result;
    cin>>n>>k>>s;
    done = false; oneCount = 0;
    result = "";
    for(int i= 0; i<n; i++){
      if(s[i]=='0'){
        if(k>=oneCount){
          result += '0';
          k = k- oneCount;
        }
        else{
          result += string(oneCount-k, '1');
          result += '0';
          result += string(k, '1');
          result += s.substr(i+1);
          cout<<result<<endl;
          done = true;
          break;
        }
      }
      else{
        oneCount++;
      }
    }
    if(!done){
      result += string(oneCount, '1');
      cout<<result<<endl;
    }
  }
  return 0;
}
