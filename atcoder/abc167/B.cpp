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
		int a, b, c, k;
		cin >> a >> b >> c >> k;
		int ans = 0;
		if(a >= k) {
			cout << k << endl;
			return 0;
		} else {
			ans += a;
			k -= a;
			if(b >= k) {
				cout << ans << endl;
				return 0;
			}
			k -= b;
			if(c >= k) {
				ans -= k;
				cout << ans << endl;
				return 0;
			}
			ans -= c;
			cout << ans << endl;
		}
	}
}