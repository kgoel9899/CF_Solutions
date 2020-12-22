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
        vector<int> c(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> c[i];
        }
        vector<string> st(n + 1), rst(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> st[i];
            string r = st[i];
            reverse(r.begin(), r.end());
            rst[i] = r;
        }
        vector<vector<int>> dp(n + 1, vector<int>(2, INF));
        dp[1][0] = 0;
        dp[1][1] = c[1];
        for(int i=2;i<=n;i++) {
            if(st[i - 1] <= st[i]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            if(rst[i - 1] <= st[i]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            if(st[i - 1] <= rst[i]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
            if(rst[i - 1] <= rst[i]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
            // for(int j=0;j<2;j++) {
            //     for(int k=0;k<2;k++) {
            //         if(s)
            //     }
            // }
        }
        int ans = min(dp[n][0], dp[n][1]);
        if(ans == INF) ans = -1;
        cout << ans << endl;
    }
}