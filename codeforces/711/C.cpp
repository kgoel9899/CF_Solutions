#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> c(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> c[i];
        }
        vector<vector<int>> p(n + 1, vector<int>(m + 1));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin >> p[i][j];
            }
        }
        int dp[n + 1][k + 1][m + 1];
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=k;j++) {
                for(int x=0;x<=m;x++) {
                    dp[i][j][x] = INF;
                }
            }
        }
        if(c[1] == 0) {
            for(int i=1;i<=m;i++) {
                dp[1][1][i] = p[1][i];
            }
        } else dp[1][1][c[1]] = 0;
        for(int i=2;i<=n;i++) {
            for(int j=1;j<=k;j++) {
                if(c[i] == 0) {
                    for(int x=1;x<=m;x++) {
                        dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][x] + p[i][x]);
                        for(int y=1;y<=m;y++) {
                            if(x == y) continue;
                            dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j - 1][y] + p[i][x]);
                        }
                    }
                } else {
                    dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i - 1][j][c[i]]);
                    for(int x=1;x<=m;x++) {
                        if(x == c[i]) continue;
                        dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i - 1][j - 1][x]);
                    }
                }
            }
        }
        int ans = INF;
        for(int i=1;i<=m;i++) {
            ans = min(ans, dp[n][k][i]);
        }
        if(ans == INF) ans = -1;
        cout << ans << endl;
    }
}