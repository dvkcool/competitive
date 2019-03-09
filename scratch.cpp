#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, ans=0;
	cin >> n;
	int a[n];
	for(int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	cout << ans;
	return 0;
}
