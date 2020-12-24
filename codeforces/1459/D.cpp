#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
// #define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e9;
const int N = 100 * 100 + 5;
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        int sum = 0;
        for(int i=1;i<=n;i++) {
            cin >> a[i] >> b[i];
            sum += b[i];
        }
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(N, -INF)));
        dp[0][0][0] = dp[1][0][0] = 0;
        int flag = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                for(int k=1;k<N;k++) {
                    if(j > i) continue;
                    dp[flag][j][k] = max(dp[flag][j][k], dp[flag ^ 1][j][k]);
                    if(k - a[i] >= 0) dp[flag][j][k] = max(dp[flag][j][k], dp[flag ^ 1][j - 1][k - a[i]] +b[i]);
                }
            }
            flag ^= 1;
        }
        flag ^= 1;
        setpres;
        for(int i=1;i<=n;i++) {
            double ans = 0.0;
            for(int j=1;j<N;j++) {
                ans = max(ans, min((double)j, (dp[flag][i][j] + sum) / 2.0));
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}