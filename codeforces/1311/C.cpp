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
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<int> v(m + 1);
		for (int i = 0; i < m; i++) {
			cin >> v[i];
		}
		v[m] = n;
		vector<vector<int>> dp(26, vector<int>(n + 1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				dp[j][i + 1] = dp[j][i];
			}
			dp[s[i] - 'a'][i + 1]++;
		}
		for (int i = 0; i < 26; i++) {
			int ans = 0;
			for (int j = 0; j <= m; j++) {
				ans += dp[i][v[j]];
			}
			cout << ans << " ";
		}
		cout << endl;
	}
}
