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
ll dfs(vector<vector<ll>> &adj, vector<ll>& st, ll n, ll curr, ll par) {
	ll temp = 1;
	for (ll i = 0; i < (ll)(adj[curr].size()); i++)
		if (adj[curr][i] != par) {
			ll temp1 = dfs(adj, st, n, adj[curr][i], curr);
			temp += temp1;
			st.push_back(temp1 * (n - temp1));
		}
	return temp;
}
int main() {
	IO();
	ll t = 1;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<vector<ll>> adj(n + 1);
		for (ll i = 0; i < n - 1; i++) {
			ll a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		ll m;
		cin >> m;
		vector<ll> pf(m);
		for (ll i = 0; i < m; i++) {
			cin >> pf[i];
		}
		vector<ll> st;
		dfs(adj, st, n, 1, 0);
		ll ans = 0;
		if (m > n - 1) {
			sort(pf.begin(), pf.end());
			sort(st.begin(), st.end());
			ll nans = 1;
			for (ll i = n - 2; i < m; i++) {
				nans = (nans * pf[i]) % MOD;
			}
			pf[n - 2] = nans;
			for (ll i = 0; i < n - 1; i++) {
				ans = (ans + (pf[i] * st[i]) % MOD) % MOD;
			}
		}
		else {
			sort(pf.begin(), pf.end(), greater<ll>());
			sort(st.begin(), st.end(), greater<ll>());
			for (ll i = 0; i < n - 1; i++) {
				if (i >= m) ans = (ans + st[i]) % MOD;
				else ans = (ans + (pf[i] * st[i]) % MOD) % MOD;
			}
		}
		cout << ans << endl;
	}
}