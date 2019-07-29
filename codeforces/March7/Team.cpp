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
	for(int i1=0, i2=0; i1<n; ++i1) {
		while(i2<n&&a[i2]-a[i1]<=5) {
			++i2;
		}
		ans=max(i2-i1, ans);
	}
	cout << ans;
	return 0;
}
