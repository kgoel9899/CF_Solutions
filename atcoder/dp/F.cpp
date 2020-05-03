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
#define out(flag) flag ? cout << "NO" << endl : cout << "YES" << endl;
#define MAX 100001
#define mod 998244353
#define inf 1e18
#define PI 3.1415926535

void IO() {
	fast;
}

int main() {

	IO();

	string s, t;
	cin >> s >> t;
	int ns = s.size(), nt = t.size();
	vector<vector<int>> dp(ns + 1, vector<int>(nt + 1));
	for (int i = 1; i <= ns; i++) {
		for (int j = 1; j <= nt; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	// cout << dp[ns][nt] << endl;
	string ans = "";
	int i = ns, j = nt;
	while (i > 0 && j > 0) {
		if (dp[i][j] == dp[i][j - 1]) j--;
		else if (dp[i - 1][j] == dp[i][j]) i--;
		else {
			ans += s[i - 1];
			i--, j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;

	return 0;
}
