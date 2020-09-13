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
	while (t--) {
		ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll mn1 = a, mx1 = b;
        ll mn2 = c, mx2 = d;
        cout << max({mn1 * mn2, mn1 * mx2, mx1 * mn2, mx1 * mx2}) << endl;
	}
}
