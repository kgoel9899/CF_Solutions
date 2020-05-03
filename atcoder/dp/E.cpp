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

	int n, w;
	cin >> n >> w;
	vector<ll> wt(n), val(n);
	ll summ = 0;
	for (ll i = 0; i < n; i++) {
		cin >> wt[i] >> val[i];
		summ += val[i];
	}
	vector<vector<ll>> dp(n + 1, vector<ll>(summ + 1, inf));
	for (int i = 0; i <= summ; i++) {
		dp[0][i] = inf;
	}
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= summ; j++) {
			dp[i][j] = dp[i - 1][j];
			if (val[i - 1] <= j) {
				dp[i][j] = min(dp[i][j], wt[i - 1] + dp[i - 1][j - val[i - 1]]);
			}
		}
	}
	ll maxi = 0;
	for (ll i = 0; i <= summ; i++) {
		if (dp[n][i] <= w) maxi = i;
	}
	cout << maxi << endl;

	return 0;
}
