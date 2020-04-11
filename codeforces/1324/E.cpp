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

int solve(int stime, int nsleeps) {
	if (nsleeps >= n) return (l <= stime && stime <= r);
	if (dp[nsleeps][stime] != -1) return dp[nsleeps][stime];
	ll ans = 0;
	if (l <= stime && stime <= r) ans = 1;
	int first = solve((stime + arr[nsleeps]) % h, nsleeps + 1);
	int second = solve((stime + arr[nsleeps] - 1) % h, nsleeps + 1);
	ans += max(first, second);
	return dp[nsleeps][stime] = ans;
}

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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < h; j++) {
			dp[i][j] = -1;
		}
	}
	cout << max(solve(arr[0], 1), solve(arr[0] - 1, 1));
	return 0;
}
