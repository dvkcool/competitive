/* Jai Mata Di */
#include <bits/stdc++.h>
using namespace std;
int pre[2000003];
string solve_palindrome(string s){
  // Using KMP
  string a = s;
  reverse(a.begin(), a.end());
  a = s + "#" + a;
  int c = 0;
  for(int i=1; i<a.length(); i++){
    while(c!= 0 && a[c] != a[i]){
      c = pre[c-1];
    }
    if(a[c]==a[i])
      c++;
    pre[i] = c;
  }
  return s.substr(0, c);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    int l = s.length();
    int i = 0;
    while(i<l-i-1 && s[i]==s[l-i-1]) i++;
    if(i>0) cout<<s.substr(0, i);

    // Check for the middle elements
    if(l > (2*i)){
      // For palindrome starting at left most position
      string t = s.substr(i, l-(2*i));
      string a = solve_palindrome(t);

      // For palindrome ending at rightmost position
      reverse(t.begin(), t.end());
      string b = solve_palindrome(t);
      if(a.length() > b.length()){
        cout<<a;
      }
      else{
        cout<<b;
      }
    }
    //cout<<"l-i: "<<l-i<<" "<<l<<" "<<i<<     "\n";
    if(i>0)
      cout<<s.substr(l-i, i);
    cout<<"\n";
  }
	return 0;
}
