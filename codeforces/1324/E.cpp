#include<bits/stdc++.h>
using namespace std;

#define ff                   first
#define ss                   second
#define ll                   long long
#define ld                   double
#define pb                   push_back
#define mp                   make_pair
#define MAX                  100001
#define mod                  998244353
#define inf                  1e18
#define w(x)                 int t; cin >> t; while(t--)
#define fori(i, a, b)        for(int i = a; i <= b; i++)
#define ford(i, b, a)        for(int i = b; i >= a; i--)
#define mk(arr,n,type)       type* arr = new type[n];
#define pii                  pair<int, int>
#define vi                   vector<int>
#define um                   unordered_map<int, int>
#define setbits(x)           __builtin_popcountll(x)
#define fast                 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int dp[2001][2001];
int arr[2001];
int n, h, l, r;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fast;

	cin >> n >> h >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < h; j++) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < h; j++) {
			if (dp[i][j] == -1) continue;
			int first = (j + arr[i]) % h;
			int second = (j + arr[i] - 1) % h;
			dp[i + 1][first] = max(dp[i + 1][first], dp[i][j] + (l <= first && first <= r));
			dp[i + 1][second] = max(dp[i + 1][second], dp[i][j] + (l <= second && second <= r));
		}
	}
	int ans = 0;
	for (int i = 0; i < h; i++) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans << endl;
	return 0;
}
