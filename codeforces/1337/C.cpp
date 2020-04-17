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
#define out(flag) flag ? cout << "NO" << endl : cout << "YES" << endl;
#define MAX 200010
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

ll child[MAX], depth[MAX], n, k;
vector<ll> adj[MAX];

ll dfs(ll ch, ll par) {
	for (ll i = 0; i < adj[ch].size(); i++) {
		ll curr = adj[ch][i];
		if (curr != par) {
			depth[curr] = depth[ch] + 1;
			child[ch] += dfs(curr, ch) + 1;
		}
	}
	return child[ch];
}

int main() {

	IO();

	cin >> n >> k;
	for (ll i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	vector<ll> diff;
	for (ll i = 1; i <= n; i++) {
		diff.pb(child[i] - depth[i]);
	}
	ll ans = 0;
	sort(diff.begin(), diff.end(), greater<ll>());
	for (ll i = 0; i < n - k; i++) {
		ans += diff[i];
	}
	cout << ans << endl;

	return 0;
}
