#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
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
		int n;
		cin >> n;
		int a = INT_MIN, b = INT_MAX;
		int c = INT_MIN, d = INT_MAX;
		for(int i=0;i<n;i++) {
			int x, y;
			cin >> x >> y;
			a = max(a, x + y);
			b = min(b, x + y);
			c = max(c, x - y);
			d = min(d, x - y);
		}
		cout << max(a - b, c - d) << endl;
	}
}