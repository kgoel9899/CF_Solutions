#include<bits/stdc++.h>
using namespace std;
#define MAX 1000010
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
		int n, m;
		cin >> n >> m;
		vector<int> v(n), mx(n);
		for(int i=0;i<n;i++) {
			cin >> v[i];
		}
		for(int i=0;i<m;i++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			mx[a] = max(mx[a], v[b]);
			mx[b] = max(mx[b], v[a]);
		}
		int ans = 0;
		for(int i=0;i<n;i++) {
			if(v[i] > mx[i]) ans++;
		}
		cout << ans << endl;
	}
}