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

	int n;
	cin >> n;
	vector<vector<int>> dp(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (i == 0) {
			dp[i][0] = a;
			dp[i][1] = b;
			dp[i][2] = c;
		} else {
			dp[i][0] = a + max(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = b + max(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = c + max(dp[i - 1][0], dp[i - 1][1]);
		}
	}
	cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;

	return 0;
}
