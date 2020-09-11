#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast;
}
int main() {
	IO();
	int t = 1;
	// cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> adj(n + 1);
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		if (v[0] != 1) {
			cout << "No" << endl;
			return 0;
		}
		queue<int> q;
		q.push(1);
		vector<int> vis(n + 1);
		int flag = 0;
		int last = 1;
		while (!q.empty()) {
			int sz = q.size();
			for (int i = 0; i < sz; i++) {
				vector<int> t1, t2;
				int f = q.front();
				q.pop();
				vis[f] = 1;
				for (int j = 0; j < adj[f].size(); j++) {
					if (vis[adj[f][j]] == 1) continue;
					t1.push_back(adj[f][j]);
				}
				for (int j = last; j < last + t1.size(); j++) {
					t2.push_back(v[j]);
				}
				sort(t1.begin(), t1.end());
				sort(t2.begin(), t2.end());
				if (t1 != t2) {
					flag = 1;
					break;
				}
				for (int j = last; j < last + t1.size(); j++) {
					q.push(v[j]);
				}
				last += t1.size();
			}
		}
		if (flag == 1) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
}
