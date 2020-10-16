#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

vector<int> ans;
void dfs(vector<vector<int>>& adj, vector<int>& col, vector<int>& dp, int curr, int par) {
	if(col[curr] == 0) dp[curr] = -1;
	else dp[curr] = 1;
	for(auto i : adj[curr]) {
		if(i == par) continue;
		dfs(adj, col, dp, i, curr);
		dp[curr] += max(0LL, dp[i]);
	}
}
void dfs2(vector<vector<int>>& adj, vector<int>& dp, int curr, int par) {
	ans[curr] = dp[curr];
	for(auto i : adj[curr]) {
		if(i == par) continue;
		dp[curr] -= max(0LL, dp[i]);
		dp[i] += max(0LL, dp[curr]);
		dfs2(adj, dp, i, curr);
		dp[i] -= max(0LL, dp[curr]);
		dp[curr] += max(0LL, dp[i]);
	}
}
int32_t main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> col(n + 1);
		for(int i=1;i<=n;i++) {
			cin >> col[i];
		}
		vector<vector<int>> adj(n + 1);
		for(int i=0;i<n-1;i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vector<int> dp(n + 1);
		dfs(adj, col, dp, 1, 0);
		ans = vector<int>(n + 1);
		dfs2(adj, dp, 1, 0);
		for(int i=1;i<=n;i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}