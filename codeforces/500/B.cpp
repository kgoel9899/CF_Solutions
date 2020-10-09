#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
void dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& v, vector<int>& conn, vector<int>& inds, int curr) {
	vis[curr] = 1;
	inds.push_back(curr);
	conn.push_back(v[curr]);
	for(auto i : adj[curr]) {
		if(vis[i] == 0) dfs(adj, vis, v, conn, inds, i);
	}
}
int main() {
	fast;
	int t = 1;
	// cin >> t;	
	while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0;i<n;i++) {
			cin >> v[i];
		}
		vector<string> mat(n);
		vector<vector<int>> adj(n);
		for(int i=0;i<n;i++) {
			cin >> mat[i];
			for(int j=0;j<n;j++) {
				if(mat[i][j] == '1') {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		vector<int> vis(n), ans(n);
		for(int i=0;i<n;i++) {
			if(vis[i] == 0) {
				vector<int> conn, inds;
				dfs(adj, vis, v, conn, inds, i);
				sort(inds.begin(), inds.end());
				sort(conn.begin(), conn.end());
				for(int i=0;i<conn.size();i++) {
					ans[inds[i]] = conn[i];
				}
			}
		}
		for(int i=0;i<n;i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}