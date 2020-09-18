#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int main() {
	fast;
	int t = 1;
	cin >> t;
	while(t--) {
		ll k, n, a, b;
		cin >> k >> n >> a >> b;
		if(a < b) {
			if(n * a >= k) cout << -1 << endl;
			else {
				ll beg = 0, last = n;
				ll ans = 0;
				while(beg <= last) {
					ll mid = (beg + last) / 2;
					if(mid * a + (n - mid) * b < k) {
						ans = mid;
						beg = mid + 1;
					} else last = mid - 1;
				}
				cout << ans << endl;
			}
		} else {
			if(n * b >= k) cout << -1 << endl;
			else {
				ll beg = 0, last = n;
				ll ans = 0;
				while(beg <= last) {
					ll mid = (beg + last) / 2;
					if(mid * a + (n - mid) * b < k) {
						ans = mid;
						beg = mid + 1;
					} else last = mid - 1;
				}
				cout << ans << endl;
			}
		}
	}
}