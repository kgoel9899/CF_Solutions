#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 205;
int R, G, B;
vector<int> r(N), g(N), b(N);
int dp[N][N][N];
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        cin >> R >> G >> B;
        for(int i=1;i<=R;i++) {
            cin >> r[i];
        }
        for(int i=1;i<=G;i++) {
            cin >> g[i];
        }
        for(int i=1;i<=B;i++) {
            cin >> b[i];
        }
        sort(r.begin() + 1, r.end(), greater<int>());
        sort(g.begin() + 1, g.end(), greater<int>());
        sort(b.begin() + 1, b.end(), greater<int>());
        int ans = 0;
        for(int i=0;i<=R;i++) {
            for(int j=0;j<=G;j++) {
                for(int k=0;k<=B;k++) {
                    if(i != 0 && j != 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + r[i] * g[j]);
                    if(i != 0 && k != 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + r[i] * b[k]);
                    if(j != 0 && k != 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + g[j] * b[k]);
                    ans = max(ans, dp[i][j][k]);
                }
            }
        }
        cout << ans << endl;
    }
}