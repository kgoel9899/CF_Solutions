#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
vector<int> ret;
void dfs(vector<vector<int>>& adj, vector<int>& vis, int n, int ch, int par) {
	vis[ch] = 1;
	ret.push_back(ch);
	for(int i=0;i<adj[ch].size();i++) {
		if(vis[adj[ch][i]] == 1 || adj[ch][i] == par) continue;
		dfs(adj, vis, n, adj[ch][i], ch);
	}
}
int main() {
	fast;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i=0;i<m;i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> vis(n + 1);
	int ans = 0;
	for(int i=1;i<=n;i++) {
		if(vis[i] == 0) {
			ret.clear();
			dfs(adj, vis, n, i, -1);
			ans = max(ans, (int)ret.size());
		}
	}
	cout << ans << endl;
}
