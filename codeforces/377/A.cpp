#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int ct = 0;
vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
void dfs(vector<string>& v, int n, int m, int r, int c, int k) {
	v[r][c] = 'O';
	ct--;
	if(ct == k) return;
	for(int i=0;i<4;i++) {
		int nx = r + dirs[i].first;
		int ny = c + dirs[i].second;
		if(nx < n && nx >= 0 && ny < m && ny >= 0 && v[nx][ny] == '.' && ct > k) dfs(v, n, m, nx, ny, k);
	}
}
int main() {
	fast;
	int t = 1;
	// cin >> t;	
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<string> v(n);
		for(int i=0;i<n;i++) {
			cin >> v[i];
			for(int j=0;j<m;j++) {
				if(v[i][j] == '.') ct++;
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(v[i][j] == '.' && ct > k) dfs(v, n, m, i, j, k);
			}
		}
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(v[i][j] == 'O') cout << '.';
				else if(v[i][j] == '#') cout << '#';
				else cout << 'X';
			}
			cout << endl;
		}
	}
}