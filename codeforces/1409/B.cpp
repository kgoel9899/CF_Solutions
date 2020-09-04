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
		ll a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;
		ll nn = n;
		ll temp = min(n, a - x);
		ll na = a - temp;
		n -= temp;
		temp = min(n, b - y);
		ll nb = b - temp;
		ll ans1 = na * nb;
		n = nn;
		temp = min(n, b - y);
		nb = b - temp;
		n -= temp;
		temp = min(n, a - x);
		na = a - temp;
		ll ans2 = na * nb;
		cout << min(ans1, ans2) << endl;
	}
}
