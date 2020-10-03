#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
void dfs(vector<vector<int>>& adj, vector<double>& v, int curr, int par) {
	v[curr] = 0.0;
	int ct = 0;
	for(auto i : adj[curr]) {
		if(i == par) continue;
		ct++;
		dfs(adj, v, i, curr);
		v[curr] += v[i] + 1.0;
	}
	if(ct != 0) v[curr] /= ct;
}
int main() {
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
		vector<double> v(n + 1);
		dfs(adj, v, 1, 0);
		cout << fixed << setprecision(7);
		cout << v[1] << endl;
	}
}