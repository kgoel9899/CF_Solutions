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
	// cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		ll ans = 0;
		for(ll i=1;i<sqrt(n);i++) {
			ans += (n - 1 - i * i) / i;
		}
		ans = 2 * ans + (ll)sqrt(n);
		if((ll)sqrt(n) * (ll)sqrt(n) == n) ans--;
		cout << ans << endl;
	}
}