#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define w(x) int t; cin >> t; while(t--)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define repd(i, b, a) for(int i = b; i >= a; i--)
#define mk(arr,n,type) type* arr = new type[n];
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define um unordered_map
#define us unordered_set
#define pqm priority_queue<int>
#define pqmi priority_queue<int, vi, greater<int>>
#define lb(v, val) lower_bound(v.begin(), v.end(), val) - v.begin();
#define ub(v, val) upper_bound(v.begin(), v.end(), val) - v.begin();
#define setbits(x) __builtin_popcountll(x)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define out(flag) flag ? cout << "NO" << endl : cout << "YES" << endl;
#define MAX 100001
#define mod 998244353
#define inf 1e18
#define PI 3.1415926535

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast;
}

int main() {

	IO();

	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		vector<ll> v(n);
		map<ll, ll> m;
		ll maxi = -1, num = -1;
		for (ll i = 0; i < n; i++) {
			cin >> v[i];
			if (v[i] % k == 0) {
				continue;
			} else {
				ll temp = (v[i] / k + 1) * k - v[i];
				m[temp]++;
				// if (m[temp] >= maxi) {
				// 	maxi = m[temp];
				// 	if (temp > num) num = temp;
				// }
			}
		}
		map<ll, ll>::iterator it = m.begin();
		ll ans = 0;
		while (it != m.end()) {
			ans = max(ans, it->first + k * (it->second - 1));
			it++;
		}
		if (ans == 0) cout << 0 << endl;
		else cout << ans + 1 << endl;
		// if (maxi == -1) cout << 0 << endl;
		// else {
		// 	cout << num << " " << maxi << endl;
		// 	ll ans = num + k * (maxi - 1);
		// 	cout << ans + 1 << endl;
		// }
	}

	return 0;
}