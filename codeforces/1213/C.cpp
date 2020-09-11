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
		ll n, m;
		cin >> n >> m;
		ll add = m, ans = 0;
		ll temp = n / m;
		temp /= 10;
		for (ll i = 0; i < 10; i++) {
			// cout << add << endl;
			ans += add % 10;
			add += m;
		}
		ans *= temp;
		ll rem = n - m * temp * 10;
		rem /= m;
		// cout << rem << endl;
		add = m;
		// cout << ans << endl;
		for (ll i = 0; i < rem; i++) {
			ans += add % 10;
			add += m;
		}
		cout << ans << endl;
	}
}
