#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
void dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& deg, vector<int>& conn, int curr) {
	vis[curr] = 1;
	conn.push_back(curr);
	for(auto i : adj[curr]) {
		deg[i]++;
		if(vis[i] == 1) continue;
		dfs(adj, vis, deg, conn, i);
	}
}
int main() {
	fast;
	int t = 1;
	// cin >> t;	
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> adj(n + 1);
		for(int i=0;i<m;i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vector<int> vis(n + 1), deg(n + 1);
		int ans = 0;
		for(int i=1;i<=n;i++) {
			if(vis[i] == 0) {
				vector<int> conn;
				dfs(adj, vis, deg, conn, i);
				int flag = 0;
				for(int i=0;i<conn.size();i++) {
					if(deg[conn[i]] != 2) {
						flag = 1;
						break;
					}
				}
				if(flag == 0) ans++;
			}
		}
		cout << ans << endl;
	}
}