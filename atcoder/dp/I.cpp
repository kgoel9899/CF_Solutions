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
        vector<double> v(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> v[i];
        }
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));
        dp[0][0] = 1.0;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<=i;j++) {
                if(j == 0) dp[i][j] = dp[i - 1][j] * (1 - v[i]);
                else dp[i][j] = dp[i - 1][j] * (1 - v[i]) + dp[i - 1][j - 1] * v[i];
            }
        }
        double ans = 0;
        for(int i=n;i>n/2;i--) {
            ans += dp[n][i];
        }
        cout << fixed << setprecision(10);
        cout << ans << endl;
    }
}