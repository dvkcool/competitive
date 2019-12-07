#include <iostream>
#include <strings.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, i, j, k, count, first, last, done;
  int b[3] = {0};
  string s;
  cin>>t;
  while(t>0){
    t--;
    cin>>s;
    done = 0;
    for(i=1; i<s.length(); i++){
      if(s[i]==s[i-1] && s[i]!='?'){
        cout<<-1<<endl;
        done = 1;
        break;
      }
    }
    if(done){
      continue;
    }
    for(i=0; i<s.length(); i++){
      if(s[i]=='?'){
        b[0]= 0; b[1] = 0; b[2] = 0;
        first = 0;
        last = 0;
        count = 1;
        for(j=i-1; j>=0; j--){
          if(s[j]!='?'){
            first = s[j]-'a';
            break;
          }
          count++;
        }
        for(j=i+1; j<s.length(); j++){
          if(s[j]!='?'){
            last = s[j] - 'a';
            break;
          }
          count++;
          if(count>3){
            break;
          }
        }
        b[first]++;
        b[last]++;
        //cout<<first<<" "<<last<<endl;
        if(count==1){
          if(first==last){
            done =1;
            cout<<-1<<endl;
            break;
          }
          for(j=0; j<3; j++){
            if(b[j]==0){
              s[i] = j + 'a';
              break;
            }
          }
        }
        else if(count == 2){
          if(first !=last){
            for(j=0; j<3; j++){
              if(b[j]==0){
                s[i] = j + 'a';
                break;
              }
            }
            s[i+1] = first + 'a';
          }
          else{
            k = i;
            for(j=0; j<3; j++){
              if(b[j]==0){
                s[k] = j + 'a';
                k++;
              }
            }
          }
        }
        else{
          for(j=0; j<3; j++){
            if(b[j]==0){
              s[i] = j + 'a';
              break;
            }
          }
        }
        //cout<<s<<endl;
      }
    }
    if(done==0){
      cout<<s<<endl;
    }
  }
	return 0;
}
