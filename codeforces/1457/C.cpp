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
    cin >> t;
    while(t--) {
        int n, p, k;
        cin >> n >> p >> k;
        string s;
        cin >> s;
        int x, y;
        cin >> x >> y;
        vector<int> dp(n);
        for(int i=0;i<n;i++) {
            if(s[i] == '0') dp[i] = 1;
        }
        for(int i=n-1;i>=0;i--) {
            if(i + k < n) dp[i] += dp[i + k];
        }
        int ans = INF;
        for(int i=p-1;i<n;i++) {
            ans = min(ans, (i - (p - 1)) * y + dp[i] * x);
        }
        cout << ans << endl;
    }
}