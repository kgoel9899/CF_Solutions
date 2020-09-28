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
		ll n;
		cin >> n;
		ll ans = INT_MAX;
		ll mx = 65000;
		for(ll i=1;i<=min(mx, n);i++) {
			ll ct = i - 1;
			ct += (n - i) / i;
			if((n - i) % i != 0) ct++;
			ans = min(ans, ct);

		}
		cout << ans << endl;
	}
}