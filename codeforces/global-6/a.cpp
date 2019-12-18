#include <iostream>
#include <strings.h>
#define lli long long int
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, zerocount, sumDigit, evenCount, threecount;
  cin>>t; string s;
  while(t>0){
    t--;
    zerocount =0; sumDigit = 0; evenCount=0;threecount=0;
    cin>>s;
    for(int i=0; i<s.length(); i++){
      sumDigit += (s[i] - '0');
      if(s[i]=='0') zerocount++;
      else if((s[i]-'0')%2==0 && s[i]!='0'){
        evenCount++;
      }
    }
    if(sumDigit%3==0 && (zerocount>=1 && evenCount >=1)){
      cout<<"red"<<endl;
    }
    else if(sumDigit%3==0 && zerocount>=2){
      cout<<"red"<<endl;
    }
    else if(sumDigit==0){
      cout<<"red"<<endl;
    }
    else{
      cout<<"cyan"<<endl;
    }

  }
	return 0;
}
