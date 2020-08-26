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
		string s;
		cin >> s;
		int x;
		cin >> x;
		int n = s.size();
		int flag = 0;
		string ans = string(n, '1');
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (i >= x) ans[i - x] = '0';
				if (i + x < n) ans[i + x] = '0';
			}
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				if (i >= x) {
					if (ans[i - x] == '1') continue;
				}
				if (i + x < n) {
					if (ans[i + x] == '1') continue;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) cout << -1 << endl;
		else cout << ans << endl;
	}
}