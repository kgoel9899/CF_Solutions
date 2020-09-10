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
		ll n, k;
		cin >> n >> k;
		vector<ll> v(n);
		for (ll i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<ll> ans;
		ll sum = 0;
		for (ll i = 0; i < n; i++) {
			sum += v[i];
			if (sum % 2 == 1 && ans.size() < k - 1) {
				ans.push_back(i + 1);
				sum = 0;
			}
		}
		if (sum % 2 == 1) {
			ans.push_back(n);
			cout << "YES" << endl;
			for (ll i = 0; i < k; i++) {
				cout << ans[i] << " ";
			}
			cout << endl;
		} else cout << "NO" << endl;
	}
}
