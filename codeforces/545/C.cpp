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
		int n;
		cin >> n;
		vector<int> x(n + 1), h(n);
		for(int i=0;i<n;i++) {
			cin >> x[i] >> h[i];
		}
		x[n] = INT_MAX;
		int prev = x[0], ans = 1;
		for(int i=1;i<n;i++) {
			if(x[i] - h[i] > prev) {
				ans++;
				prev = x[i];
			} else if(x[i] + h[i] < x[i + 1]) {
				ans++;
				prev = x[i] + h[i];
			} else prev = x[i];
		}
		cout << ans << endl;
	}
}