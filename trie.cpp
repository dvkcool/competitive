#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e5;
int n;
string s[mxN];

struct trie {
	int nodes, child[mxN+1][676], count[mxN+1];

	void insert(vector<int> s) {
		int u=0;
		for(int si : s) {
			if(!child[u][si])
				child[u][si]=nodes++;
			u=child[u][si];
		}
		++count[u];
	}

	ll dfs(int u=0, ll lp=0) {
		ll ans=0;
		//go to deeper nodes first
		for(int i=0; i<676; ++i) {
			if(child[u][i]) {
				ans+=dfs(child[u][i], lp+1);
				count[u]+=count[child[u][i]];
			}
		}
		//match whenever we can
		while(count[u]>=2) {
			count[u]-=2;
			ans+=lp*lp;
		}
		return ans;
	}
} tr;

void solve() {
	//input
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> s[i];

	//main
	//reset trie
	memset(tr.child, 0, sizeof(tr.child[0])*tr.nodes);
	memset(tr.count, 0, 4*tr.nodes);
	tr.nodes=1;
	//convert strings
	//instead of storing (char, char), represent each pair as an integer from 0 to 26^2-1=675
	for(int i=0; i<n; ++i) {
		vector<int> a=vector<int>(s[i].size());
		string t=s[i];
		reverse(t.begin(), t.end());
		for(int j=0; j<s[i].size(); ++j)
			a[j]=(s[i][j]-'a')*26+(t[j]-'a');
		//insert string into trie
		tr.insert(a);
	}

	cout << tr.dfs() << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}
