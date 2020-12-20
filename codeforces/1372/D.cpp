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
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<int> dp;
        for(int i=0;i<n;i+=2) {
            dp.push_back(v[i]);
        }
        for(int i=1;i<n;i+=2) {
            dp.push_back(v[i]);
        }
        for(int i=0;i<n;i++) {
            dp.push_back(dp[i]);
        }
        int ans = 0, curr = 0;
        for(int i=0;i<2*n;i++) {
            if(i >= (n + 1) / 2) {
                ans = max(ans, curr);
                curr += dp[i];
                curr -= dp[i - (n + 1) / 2];
            } else curr += dp[i];
        }
        cout << ans << endl;
    }
}