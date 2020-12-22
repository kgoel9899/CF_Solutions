#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 1e6 + 5;
vector<int> vis(N), dp(N);
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
            vis[v[i]] = 1;
        }
        int ans = 1;
        for(int i=1;i<N;i++) {
            if(vis[i] == 1) {
                dp[i]++;
                ans = max(ans, dp[i]);
                for(int j=2*i;j<N;j+=i) {
                    dp[j] = max(dp[j], dp[i]);
                }
            }
        }
        cout << ans << endl;
    }
}