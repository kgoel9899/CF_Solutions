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
		ll n;
		cin >> n;
		vector<ll> a(n), b(n);
		ll x = INT_MAX, y = INT_MAX;
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
			x = min(x, a[i]);
		}
		for (ll i = 0; i < n; i++) {
			cin >> b[i];
			y = min(y, b[i]);
		}
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			ll p = a[i] - x, q = b[i] - y;
			if (p > q) {
				ans += q;
				p -= q;
				ans += p;
			} else {
				ans += p;
				q -= p;
				ans += q;
			}
		}
		cout << ans << endl;
	}
}
