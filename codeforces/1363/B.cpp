#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define w(x) int t; cin >> t; while(t--)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define repd(i, b, a) for(int i = b; i >= a; i--)
#define mk(arr,n,type) type* arr = new type[n];
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define um unordered_map
#define us unordered_set
#define pqm priority_queue<int>
#define pqmi priority_queue<int, vi, greater<int>>
#define lb(v, val) lower_bound(v.begin(), v.end(), val) - v.begin();
#define ub(v, val) upper_bound(v.begin(), v.end(), val) - v.begin();
#define setbits(x) __builtin_popcountll(x)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define out(flag) flag ? cout << "NO" << endl : cout << "YES" << endl;
#define MAX 100001
#define mod 998244353
#define inf 1e18
#define PI 3.1415926535

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast;
}
int main() {

	IO();

	int t;
	cin >> t;
	while (t) {
		t--;
		string s;
		cin >> s;
		int n = s.length(), one = 0, zero = 0;
		vector<vector<int>> dp(n, vector<int>(2));
		if (s[0] == '1') dp[0][1] = 1;
		else dp[0][0] = 1;
		for (int i = 1; i < n; i++) {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			if (s[i] == '1') dp[i][1] += 1;
			else dp[i][0] += 1;
		}
		if (dp[n - 1][0] == 0 || dp[n - 1][1] == 0) cout << 0 << endl;
		else {
			int ans = min(dp[n - 1][0], dp[n - 1][1]);
			for (int i = 0; i < n; i++) {
				int x = dp[i][0];
				ans = min(ans, i + 1 - x + dp[n - 1][0] - x);
			}
			for (int i = 0; i < n; i++) {
				int x = dp[i][1];
				ans = min(ans, i + 1 - x + dp[n - 1][1] - x);
			}
			cout << ans << endl;
		}
	}

	return 0;
}
