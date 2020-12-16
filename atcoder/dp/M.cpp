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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<vector<int>> dp(n, vector<int>(k + 1));
        for(int i=0;i<=v[0];i++) {
            dp[0][i] = 1;
        }
        for(int i=1;i<n;i++) {
            vector<int> pref(k + 1);
            pref[0] = dp[i - 1][0];
            for(int j=1;j<=k;j++) {
                pref[j] += pref[j - 1] + dp[i - 1][j];
                pref[j] %= MOD;
            }
            for(int j=0;j<=k;j++) {
                if(j - v[i] - 1 >= 0) dp[i][j] += pref[j] - pref[j - v[i] - 1] + MOD;
                else dp[i][j] += pref[j];
                dp[i][j] %= MOD;
            }
        }
        cout << dp[n - 1][k] << endl;
    }
}