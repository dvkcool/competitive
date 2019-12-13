#include <iostream>
#include <strings.h>
#define lli long long int
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); lli result =0, len =0;
  string s; int n, k, i; char c;
  int charcount[26] = {0};
  cin>>n>>k;
  cin>>s;
  for(i=0; i<k; i++){
    cin>>c;
    charcount[c-'a']++;
  }
  for(i=0; i<s.length(); i++){
    if(!charcount[s[i]-'a']){
        result += (len * (len+1))/2;
        len = 0;
    }
    else{
      len++;
    }
  }
  if(len!=0){
    result += (len * (len+1))/2;
    len = 0;
  }
  cout<<result<<endl;

	return 0;
}
