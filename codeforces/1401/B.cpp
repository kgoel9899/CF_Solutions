#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 998244353
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
	ll t = 1;
	cin >> t;
	while (t--) {
		ll a, b, c;
		ll x, y, z;
		cin >> a >> b >> c >> x >> y >> z;
		ll ans = 0;
		ans += 2 * min(c, y);
		ll t1 = min(c, y);
		c -= t1;
		y -= t1;
		if (b > x + y) ans -= min(b - x - y, z) * 2;
		// ll ans = 0;
		// int t1 = min(c, y);
		// ans += 2 * t1;
		// c -= t1;
		// y -= t1;
		// int t2 = min(c, z);
		// c -= t2;
		// z -= t2;
		// int t3 = min(c, x);
		// c -= t3;
		// x -= t3;
		// int t4 = min(b, y);
		// b -= t4;
		cout << ans << endl;
	}
}
