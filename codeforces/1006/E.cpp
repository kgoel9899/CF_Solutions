#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
vector<int> one;
void dfs(vector<vector<int>>& adj, vector<int>& count, int curr, int par) {
	count[curr]++;
	one.push_back(curr);
	for(auto i : adj[curr]) {
		if(i == par) continue;
		dfs(adj, count, i, curr);
		count[curr] += count[i];
	}
}
int main() {
	fast;
	int t = 1;
	// cin >> t;	
	while(t--) {
		int n, q;
		cin >> n >> q;
		vector<int> v(n - 1);
		vector<vector<int>> adj(n + 1);
		for(int i=0;i<n-1;i++) {
			cin >> v[i];
			adj[v[i]].push_back(i + 2);
			adj[i + 2].push_back(v[i]);
		}
		vector<int> count(n + 1);
		dfs(adj, count, 1, 0);
		map<int, int> mp;
		for(int i=0;i<n;i++) {
			mp[one[i]] = i;
		}
		for(int i=0;i<q;i++) {
			int a, b;
			cin >> a >> b;
			int ind = mp[a];
			if(b > count[a] || ind + b - 1 >= one.size()) cout << -1 << endl;
			else cout << one[ind + b - 1] << endl;
		}
	}
}