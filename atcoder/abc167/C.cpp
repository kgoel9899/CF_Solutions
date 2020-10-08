#include<bits/stdc++.h>
using namespace std;
#define mx 1000010
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--) {
		int n, m, x;
		cin >> n >> m >> x;
		vector<vector<int>> v(n, vector<int>(m));
		vector<int> c(n);
		for(int i=0;i<n;i++) {
			cin >> c[i];
			for(int j=0;j<m;j++) {
				cin >> v[i][j];
			}
		}
		int ans = INT_MAX;
		for(int mask=0;mask<1<<n;mask++) {
			vector<int> temp(m);
			int curr = 0;
			for(int i=0;i<n;i++) {
				if(((mask >> i) & 1) == 0) continue;
				curr += c[i];
				for(int j=0;j<m;j++) {
					temp[j] += v[i][j];
				}
			}
			int flag = 0;
			for(int i=0;i<m;i++) {
				if(temp[i] < x) {
					flag = 1;
					break;
				}
			}
			if(flag == 0) ans = min(ans, curr);
		}
		if(ans == INT_MAX) cout << -1 << endl;
		else cout << ans << endl;
	}
}