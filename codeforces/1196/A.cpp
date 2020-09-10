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
	int t = 1;
	cin >> t;
	while (t--) {
		vector<ll> v(3);
		cin >> v[0] >> v[1] >> v[2];
		sort(v.begin(), v.end());
		ll a = v[0], b = v[1], c = v[2];
		ll ans = (b + c - a) / 2;
		cout << min(a + ans, b + ans) << endl;
	}
}
