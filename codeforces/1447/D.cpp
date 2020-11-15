#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 5010;
int dp[N][N];
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        int mx = INT_MIN;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]) - 1);
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
                mx = max(mx, dp[i][j]);
            }
        }
        cout << mx << endl;
    }
}