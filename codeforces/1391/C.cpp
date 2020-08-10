#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
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
	// cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll fact = 1, two = 1;
		for (ll i = 1; i < n; i++) {
			fact *= i;
			two *= 2;
			fact %= MOD;
			two %= MOD;
		}
		fact *= n;
		fact %= MOD;
		cout << (fact - two + MOD) % MOD << endl;
	}
}
