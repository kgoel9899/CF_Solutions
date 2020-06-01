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

void dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& count, int x) {
	vis[x] = 1;
	count[x] = 1;
	for (int i = 0; i < adj[x].size(); i++) {
		if (vis[adj[x][i]] == 0) {
			dfs(adj, vis, count, adj[x][i]);
			count[x] += count[adj[x][i]];
		}
	}
	return;
}

int main() {

	IO();

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		if (n == 1) cout << "Ayush" << endl;
		else {
			vector<vector<int>> adj(n + 1);
			vector<int> tot(n + 1);
			for (int i = 0; i < n - 1; i++) {
				int a, b;
				cin >> a >> b;
				adj[a].push_back(b);
				adj[b].push_back(a);
				tot[a]++;
				tot[b]++;
			}
			if (tot[x] <= 1) cout << "Ayush" << endl;
			else {
				vector<int> vis(n + 1), count(n + 1);
				dfs(adj, vis, count, x);
				for (int i = 1; i <= n; i++) {
					if (count[i] != 0) count[i]--;
				}
				int ct = 0;
				for (int i = 0; i < adj[x].size(); i++) {
					ct += count[adj[x][i]];
				}
				ct += adj[x].size() - 1;
				if (ct % 2 == 1) cout << "Ashish" << endl;
				else cout << "Ayush" << endl;
			}
		}
	}

	return 0;
}