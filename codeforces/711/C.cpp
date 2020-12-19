#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 105;
int dp[N][N][N];
int c[N];
int p[N][N];
int n, m, k;
int helper(int curr, int tot, int prev) {
    if(tot > k) return INF;
    if(curr == n + 1) {
        if(tot == k) return 0;
        else return INF;
    }
    if(dp[curr][tot][prev] != -1) return dp[curr][tot][prev];
    if(c[curr] != 0) return dp[curr][tot][prev] = helper(curr + 1, tot + (c[curr] != prev), c[curr]);
    else {
        int ans = INF;
        for(int i=1;i<=m;i++) {
            ans = min(ans, p[curr][i] + helper(curr + 1, tot + (i != prev), i));
        }
        return dp[curr][tot][prev] = ans;
    }
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        for(int i=1;i<=n;i++) {
            cin >> c[i];
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin >> p[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        int ans = helper(1, 0, 0);
        if(ans == INF) ans = -1;
        cout << ans << endl;
    }
}