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
	int t = 1;
	cin >> t;
	while (t--) {
		ll r, g, b, w;
		cin >> r >> g >> b >> w;
		ll odd = 0;
		if (r % 2 == 1) odd++;
		if (g % 2 == 1) odd++;
		if (b % 2 == 1) odd++;
		if (w % 2 == 1) odd++;
		if (odd <= 1) cout << "YES" << endl;
		else {
			odd = 0;
			if (r > 0 && g > 0 && b > 0) {
				r--;
				g--;
				b--;
				w += 3;
				if (r % 2 == 1) odd++;
        		if (g % 2 == 1) odd++;
        		if (b % 2 == 1) odd++;
        		if (w % 2 == 1) odd++;
				if (odd <= 1) cout << "YES" << endl;
				else cout << "NO" << endl;
			} else cout << "NO" << endl;
		}
	}
}
