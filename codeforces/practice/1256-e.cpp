#include <iostream>
#include <algorithm>
using namespace std;
class student{
public:
  int skill;
  int pos;
  student(){
    skill =0;
    pos = 0;
  }
};
bool studentCompare(student const & a, student const & b){
  return a.skill < b.skill;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n; cin>>n;
  student s[n];
  for(int i=0; i<n; i++){
    cin>>s[i].skill;
    s[i].pos = i;
  }
  sort(s, s+n, studentCompare);
  int result[n+1], diff[n+1], p[n+1];
  for(int i=0; i<=n; i++){
    result[i] = 0;
    diff[i] = 1000000001;
    p[i] = 0;
  }
  diff[0] = 0;
  for(int i=0; i<n; i++){
    for(int j=3; j<=5 && i+j <=n; j++){
      int d = s[i+j-1].skill - s[i].skill;
      if(diff[i+j] > diff[i]+d){
        diff[i+j] = diff[i]+d;
        p[i+j] = i;
        //cout<<i+j<<" "<<diff[i+j]<<endl;
      }
    }
  }
  int team = 0;
  int cur = n;
    while(cur!=0){
      for(int i= cur-1; i>=p[cur] && i>=0; i--){
        result[min(max(s[i].pos,0), n)] = team +1;
        //cout<<cur<<" "<<i<<" "<<s[i].pos<<" "<<team<<" "<<result[s[i].pos]<<endl;
      }
      cur = p[cur];
      team++;
      //cout<<team<<endl;
    }

  cout<<diff[n]<<" "<<team<<endl;
  for(int i=0; i<n; i++){
    cout<<result[i]<<" ";
  }
  cout<<endl;
}
