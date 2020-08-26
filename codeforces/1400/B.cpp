#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 998244353
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast;
}
int main() {
	IO();
	ll t = 1;
	cin >> t;
	while (t--) {
		ll p, f;
		cin >> p >> f;
		ll cnts, cntw;
		cin >> cnts >> cntw;
		ll s, w;
		cin >> s >> w;
		ll ans = 0;
		ll P = p, F = f;
		ll CNTS = cnts, CNTW = cntw;
		for (ll i = 0; i <= cnts; i++) {
			ll temp = 0;
			if (i * s <= p) {
				temp += i;
				CNTS -= i;
				P -= i * s;
			}
			ll takew = min(P / w, CNTW);
			temp += takew;
			P -= takew * w;
			CNTW -= takew;
			if (s <= w) {
				ll take1s = min(CNTS, F / s);
				F -= take1s * s;
				CNTS -= take1s;
				ll take1w = min(CNTW, F / w);
				temp += take1s + take1w;
			} else {
				ll take1w = min(CNTW, F / w);
				F -= take1w * w;
				CNTW -= take1w;
				ll take1s = min(CNTS, F / s);
				temp += take1s + take1w;
			}
			ans = max(ans, temp);
			P = p;
			F = f;
			CNTS = cnts;
			CNTW = cntw;
		}
		cout << ans << endl;
	}
}
