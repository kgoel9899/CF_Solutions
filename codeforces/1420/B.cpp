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
		ll n;
		cin >> n;
		vector<ll> v(n);
		vector<ll> ct(33);
		for(ll i=0;i<n;i++) {
			cin >> v[i];
			for(ll j=31;j>=0;j--) {
				if(((v[i] >> j) & 1) == 1) {
					ct[j]++;
					break;
				}
			}
		}
		ll ans = 0;
		for(ll i=0;i<33;i++) {
			ans += (ct[i] * (ct[i] - 1)) / 2;
		}
		cout << ans << endl;
	}
}