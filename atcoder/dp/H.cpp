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
#define MOD 1000000007
#define inf 1e18
#define PI 3.1415926535

void IO() {
	fast;
}

int main() {

	IO();

	int h, w;
	cin >> h >> w;
	vector<vector<char>> sq(h, vector<char>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> sq[i][j];
		}
	}
	vector<vector<int>> dp(h, vector<int>(w, 0));
	for (int i = 0; i < h; i++) {
		if (sq[i][0] == '#') break;
		dp[i][0] = 1;
	}
	for (int i = 0; i < w; i++) {
		if (sq[0][i] == '#') break;
		dp[0][i] = 1;
	}
	for (int i = 1; i < h; i++) {
		for (int j = 1; j < w; j++) {
			if (sq[i][j] != '#') {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
			}
		}
	}
	cout << dp[h - 1][w - 1] << endl;

	return 0;
}
