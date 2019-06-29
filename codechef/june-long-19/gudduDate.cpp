#include <bits/stdc++.h>
using namespace std;
void solve(){
  unsigned long long int n;
  cin >> n;
  unsigned long long int a;
  a = n;
  a = a*9;
  a = a + 10;
  cout <<a<<"\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cases;
	cin >> cases;
	for(int i=0; i<cases; ++i)
		solve();
	return 0;
}
