#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 998244353
#define int long long int
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
int32_t main() {
	IO();
	int t = 1;
	// cin >> t;
	while (t--) {
		string s;
		cin >> s;
		string ans = "";
		int n = s.size(), ct = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') ct++;
		}
		int i = 0;
		for (; i < n; i++) {
			if (s[i] == '2') break;
			if (s[i] == '0') ans += '0';
		}
		ans += string(ct, '1');
		for (; i < n; i++) {
			if (s[i] != '1') ans += s[i];
		}
		cout << ans << endl;
	}
}
