#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
vector<int> ret;
int dfs(vector<vector<pair<int, int>>>& adj, int ch, int par) {
	int ans = 0;
	for(auto i : adj[ch]) {
		if(i.first == par) continue;
		int temp = dfs(adj, i.first, ch);
		if(temp == 0 && i.second == 2) {
			ret.push_back(i.first);
			temp++;
		}
		ans += temp;
	}
	return ans;
}
int main() {
	fast;
	int t = 1;
	// cin >> t;	
	while(t--) {
		int n;
		cin >> n;
		vector<vector<pair<int, int>>> adj(n + 1);
		for(int i=0;i<n-1;i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}
		cout << dfs(adj, 1, 0) << endl;
		for(int i=0;i<ret.size();i++) {
			cout << ret[i] << " ";
		}
		cout << endl;
	}
}