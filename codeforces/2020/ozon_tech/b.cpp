/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    vector<int> opbrack;
    vector<int> clbrack;
    for(int i=0; i<s.length(); i++){
      if(s[i]=='('){
        opbrack.push_back(i);
      }
      else{
        clbrack.push_back(i);
      }
    }
    int opn = opbrack.size();
    int op = 0;
    int cp = clbrack.size() -1;
    vector<int> result;
    while(op<opn && cp>=0 && opbrack[op] < clbrack[cp]){
      result.push_back(opbrack[op]+1);
      result.push_back(clbrack[cp]+1);
      op++;
      cp--;
    }
    if(result.size()){
      cout<<"1\n";
      cout<<result.size()<<"\n";
      sort(result.begin(), result.end());
      for(int q: result) cout<<q<<" ";
      cout<<"\n";
    }
    else{
      cout<<"0\n";
    }
  return 0;
}
