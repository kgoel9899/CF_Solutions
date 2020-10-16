#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int main() {
	fast;
	int t = 1;
	// cin >> t;	
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<int> col(n + 1);
		int mn = INT_MAX;
		for(int i=1;i<=n;i++) {
			cin >> col[i];
			mn = min(mn, col[i]);
		}
		vector<vector<int>> adj(n + 1);
		for(int i=0;i<m;i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		map<int, set<int>> mm;
		for(int i=1;i<=n;i++) {
			for(auto j : adj[i]) {
				if(col[j] != col[i]) mm[col[i]].insert(col[j]);
			}
		}
		int mx = 0, ans = 0;
		for(auto i : mm) {
			if(i.second.size() > mx) {
				mx = i.second.size();
				ans = i.first;
			}
		}
		if(ans == 0) cout << mn << endl;
		else cout << ans << endl;
	}
}