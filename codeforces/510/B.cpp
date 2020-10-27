#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int ans = 0;
void dfs(vector<string>& v, vector<vector<int>>& vis, int n, int m, int r, int c, int parx, int pary, char cc) {
	// cout << r << " " << c << endl;
	vis[r][c] = 1;
	for(int i=0;i<4;i++) {
		int nx = r + dirs[i].first;
		int ny = c + dirs[i].second;
		// cout << r << " " << c << " " << nx << " " << ny << endl;
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && !(parx == nx && pary == ny) && v[nx][ny] == cc) {
			if(vis[nx][ny] == 1) {
				ans = 1;
				return;
			}
			dfs(v, vis, n, m, nx, ny, r, c, cc);
		}
	}
}
int main() {
	fast;
	int t = 1;
	// cin >> t;	
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<string> v(n);
		for(int i=0;i<n;i++) {
			cin >> v[i];
		}
		vector<vector<int>> vis(n, vector<int>(m));
		int ct = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(vis[i][j] == 0) {
					// cout << endl;
					// cout << endl;
					char c = v[i][j];
					ans = 0;
					dfs(v, vis, n, m, i, j, -1, -1, c);
					if(ans == 1) ct++;
				}
			}
		}
		if(ct > 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}