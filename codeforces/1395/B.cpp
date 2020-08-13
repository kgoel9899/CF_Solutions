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
	// cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int x, y;
		cin >> x >> y;
		int savex = x, savey;
		while (true) {
			if (x > n) break;
			for (int i = y; i <= m; i++) {
				cout << x << " " << i << endl;
			}
			x++;
			savey = m;
			if (x > n) break;
			for (int i = m; i >= y; i--) {
				cout << x << " " << i << endl;
			}
			x++;
			savey = y;
			if (x > n) break;
		}
		x = savex - 1;
		while (true) {
			if (savey == y) {
				if (x <= 0) break;
				for (int i = y; i <= m; i++) {
					cout << x << " " << i << endl;
				}
				x--;
				if (x <= 0) break;
				for (int i = m; i >= y; i--) {
					cout << x << " " << i << endl;
				}
				x--;
				if (x <= 0) break;
			} else {
				if (x <= 0) break;
				for (int i = m; i >= y; i--) {
					cout << x << " " << i << endl;
				}
				x--;
				if (x <= 0) break;
				for (int i = y; i <= m; i++) {
					cout << x << " " << i << endl;
				}
				x--;
				if (x <= 0) break;
			}
		}
		x = 1;
		savey = y;
		y = 1;
		if (savex > 1) {
			while (true) {
				if (y >= savey) break;
				for (int i = 1; i <= n; i++) {
					cout << i << " " << y << endl;
				}
				y++;
				if (y >= savey) break;
				for (int i = n; i > 0; i--) {
					cout << i << " " << y << endl;
				}
				y++;
				if (y >= savey) break;
			}
		}
	}
}
