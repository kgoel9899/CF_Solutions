#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
set<int> s[2];
void dfs(vector<vector<int>>& adj, int curr, int par, int col) {
	s[col].insert(curr);
	for(auto i : adj[curr]) {
		if(i == par) continue;
		dfs(adj, i, curr, 1 - col);
	}
}
int32_t main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<vector<int>> adj(n + 1);
		for(int i=0;i<n-1;i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(adj, 1, 0, 0);
		int ans = 0;
		for(auto i : s[0]) {
			ans += s[1].size() - adj[i].size();
		}
		for(auto i : s[1]) {
			ans += s[0].size() - adj[i].size();
		}
		cout << ans / 2 << endl;
	}
}