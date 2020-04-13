#include<bits/stdc++.h>
using namespace std;

#define ff                   first
#define ss                   second
#define ll                   long long
#define ld                   double
#define pb                   push_back
#define mp                   make_pair
#define MAX                  100001
#define mod                  998244353
#define inf                  1e18
#define w(x)                 int t; cin >> t; while(t--)
#define fori(i, a, b)        for(int i = a; i <= b; i++)
#define ford(i, b, a)        for(int i = b; i >= a; i--)
#define mk(arr,n,type)       type* arr = new type[n];
#define pii                  pair<int, int>
#define vi                   vector<int>
#define um                   unordered_map<int, int>
#define setbits(x)           __builtin_popcountll(x)
#define fast                 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define out(flag)            if(flag == 1) cout << "NO" << endl; else cout << "YES" << endl;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fast;

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll a[n], b[n];
		for (ll i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		ll ans = a[0];
		for (ll i = 1; i < n; i++) {
			ll diff = a[i] - b[i - 1];
			if (diff > 0) ans += diff;
		}
		ll last = n - 1;
		ll nans = ans;
		for (ll i = 1; i < n; i++) {
			ll diff = a[i] - b[i - 1];
			nans = nans - a[i - 1] + a[i];
			if (diff > 0) nans -= a[i] - b[i - 1];
			ll ndiff = a[(last + 1) % n] - b[last % n];
			if (ndiff > 0) nans += ndiff;
			last = (last + 1) % n;
			ans = min(ans, nans);
		}
		cout << ans << endl;
	}

	return 0;
}