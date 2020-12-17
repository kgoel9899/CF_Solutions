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
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> v[i][j];
            }
        }
        int mx = 1 << n;
        vector<vector<int>> dp(n + 1, vector<int>(mx));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++) {
            for(int mask=0;mask<mx;mask++) {
                int bits = __builtin_popcount(mask);
                if(bits != i) continue;
                for(int j=0;j<n;j++) {
                    if((mask & (1 << j)) && v[i - 1][j] == 1) {
                        dp[i][mask] += dp[i - 1][mask - (1 << j)];
                        dp[i][mask] %= MOD;
                    }
                }
            }
        }
        cout << dp[n][mx - 1] << endl;
    }
}