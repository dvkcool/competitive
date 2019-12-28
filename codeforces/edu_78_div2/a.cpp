#include <iostream>
#include <strings.h>
#define lli long long int
using namespace std;
int main() {
ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
       int t;
    cin>>t;
    while(t>0){
    t--;
    string p, h;
    cin>>p>>h;
    if(h.length()<p.length()){
        cout<<"NO"<<endl;
        continue;
}
else{
    int c = 0; int done = 0;
    int a[26] = {0}; int b[26];
    for(int i=0; i<p.length(); i++){
      a[p[i]-'a']++;
    }
    for(int i=0; i<h.length() && i+p.length() <=h.length(); i++){
        for(int j=0; j<26; j++){
          b[j] = 0;
        }
        for(int j=0; j<p.length(); j++){
            b[h[j+i]-'a']++;
        }
        c=0;
        for(int j=0; j<26; j++){
          if(a[j]==b[j]){
            c++;
          }
          else{
            break;
          }
        }
        if(c==26){
          cout<<"YES"<<endl;
          done = 1;
          break;

        }
}
if(done==0)
cout<<"NO"<<endl;

}
}
        return 0;
}
