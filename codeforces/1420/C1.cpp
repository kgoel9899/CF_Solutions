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
	ll t = 1;
	cin >> t;
	while(t--) {
		ll n, q;
		cin >> n >> q;
		vector<ll> v(n);
		for(ll i=0;i<n;i++) {
			cin >> v[i];
		}
		vector<ll> a(n);
		a[0] = 1;
		for(ll i=1;i<n;i++) {
			if(v[i] >= v[i - 1]) a[i] = 1;
			else a[i] = -1;
		}
		// for(int i=0;i<n;i++) {
		// 	cout << a[i] << " ";
		// }
		// cout << endl;
		ll curr = 1;
		ll ans = 0;
		ll mx = 1;
		for(ll i=0;i<=n;i++) {
			if((i == n && curr == 1) || (i != n && a[i] != curr)) {
				// cout << curr << " " << v[i - 1] << endl;
				ans += curr * v[i - 1];
				curr *= -1;
			}
			mx = max(mx, v[i]);
		}
		if(ans == 0) cout << mx << endl;
		else cout << ans << endl;
	}
}