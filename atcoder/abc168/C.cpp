#include<bits/stdc++.h>
using namespace std;
#define mx 1000010
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--) {
		double a, b, h, m;
		cin >> a >> b >> h >> m;
		double ang = 6 * m;
		double ang1 = 30 * h + 0.5 * m;
		double angle = abs(ang - ang1);
		angle = min(angle, 360 - angle);
		cout << fixed << setprecision(10);
		double ans = a * a + b * b - 2 * a * b * cos(angle * M_PI / 180.0);
		cout << sqrt(ans) << endl;
	}
}