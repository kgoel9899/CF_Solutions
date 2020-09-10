#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast;
}
int main() {
	IO();
	int t = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int t = 1e5, r = 1e5, dd = -1e5, l = -1e5;
		for (int i = 0; i < n; i++) {
			int x, y, a, b, c, d;
			cin >> x >> y >> a >> b >> c >> d;
			if (a == 0) l = max(l, x);
			if (b == 0) t = min(t, y);
			if (c == 0) r = min(r, x);
			if (d == 0) dd = max(dd, y);
		}

		if (t < dd || r < l) cout << 0 << endl;
		else cout << 1 << " " << l << " " << t << endl;
	}
}
