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
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for(int i=0;i<n;i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int ans = 0;
		for(int i=0;i<k;i++) {
			ans += v[i];
		}
		cout << ans << endl;
	}
}