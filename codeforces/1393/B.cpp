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
		int n;
		cin >> n;
		vector<int> v(n);
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			m[v[i]]++;
		}
		int q;
		cin >> q;
		int c2 = 0, c4 = 0, c6 = 0, c8 = 0;
		for (auto i : m) {
			if (i.second >= 8) c8++;
			else if (i.second >= 6) c6++;
			else if (i.second >= 4) c4++;
			else if (i.second >= 2) c2++;
		}
		while (q--) {
			char c;
			cin >> c;
			int x;
			cin >> x;
			if (c == '+') {
				int prev = m[x];
				m[x]++;
				int ne = m[x];
				if (ne == 8) {
					c8++;
					c6--;
				} else if (ne == 6) {
					c6++;
					c4--;
				} else if (ne == 4) {
					c4++;
					c2--;
				} else if (ne == 2) c2++;
			} else {
				int prev = m[x];
				m[x]--;
				int ne = m[x];
				if (ne == 7) {
					c8--;
					c6++;
				} else if (ne == 5) {
					c6--;
					c4++;
				} else if (ne == 3) {
					c4--;
					c2++;
				} else if (ne == 1) c2--;
			}
			bool ans = (c8 >= 1) || ((c6 > 1) || (c6 == 1 && (c4 >= 1 || c2 >= 1))) || ((c4 > 1) || (c4 == 1 && c2 >= 2));
			if (ans) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}
