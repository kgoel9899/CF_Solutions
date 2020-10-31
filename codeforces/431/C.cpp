#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 105;
int dp[N][N];
int32_t main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, kk, d;
        cin >> n >> kk >> d;
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=kk;i++) {
            dp[1][i] = 1;
        }
        for(int i=2;i<N;i++) {
            for(int j=i;j<=n;j++) {
                for(int k=1;k<=kk&&(j-k)>=1;k++) {
                    dp[i][j] += dp[i - 1][j - k];
                    dp[i][j] %= MOD;
                }
            }
        }
        int ans1 = 0, ans2 = 0;
        for(int i=1;i<N;i++) {
            ans1 += dp[i][n];
            ans1 %= MOD;
        }
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=d-1;i++) {
            dp[1][i] = 1;
        }
        for(int i=2;i<N;i++) {
            for(int j=i;j<=n;j++) {
                for(int k=1;k<=d-1&&(j-k)>=1;k++) {
                    dp[i][j] += dp[i - 1][j - k];
                    dp[i][j] %= MOD;
                }
            }
        }
        for(int i=1;i<N;i++) {
            ans2 += dp[i][n];
            ans2 %= MOD;
        }
        cout << (ans1 - ans2 + MOD) % MOD << endl;
    }
}