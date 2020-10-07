#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
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
		int h, w, k;
		cin >> h >> w >> k;
		vector<string> v(h);
		for(int i=0;i<h;i++) {
			cin >> v[i];
		}
		int ans = 0;
		for(int row=0;row<1<<h;row++) {
			for(int col=0;col<1<<w;col++) {
				int curr = 0;
				for(int i=0;i<h;i++) {
					if(((row >> i) & 1) == 1) continue;
					for(int j=0;j<w;j++) {
						if(((col >> j) & 1) == 1) continue;
						if(v[i][j] == '#') curr++;
					}
				}
				if(curr == k) ans++;
			}
		}
		cout << ans << endl;
	}
}