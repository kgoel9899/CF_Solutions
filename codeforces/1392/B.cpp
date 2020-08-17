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
		ll n, k;
		cin >> n >> k;
		vector<ll> v(n);
		ll mx = INT_MIN;
		for (ll i = 0; i < n; i++) {
			cin >> v[i];
			mx = max(mx, v[i]);
		}
		for (ll i = 0; i < n; i++) {
			v[i] = mx - v[i];
		}
		k--;
		if (k % 2 == 0) {
			for (ll i = 0; i < n; i++) {
				cout << v[i] << " ";
			}
			cout << endl;
		} else {
			mx = INT_MIN;
			for (ll i = 0; i < n; i++) {
				mx = max(mx, v[i]);
			}
			for (ll i = 0; i < n; i++) {
				v[i] = mx - v[i];
				cout << v[i] << " ";
			}
			cout << endl;
		}
	}
}