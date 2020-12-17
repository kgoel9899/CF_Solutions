#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 405;
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
        vector<vector<int>> dp(n, vector<int>(n));
        for(int L=n-1;L>=0;L--) {
            for(int R=L;R<n;R++) {
                if(L == R) dp[L][R] = 0;
                else {
                    dp[L][R] = INF;
                    int sum = 0;
                    for(int i=L;i<=R;i++) {
                        sum += v[i];
                    }
                    for(int i=L;i<R;i++) {
                        dp[L][R] = min(dp[L][R], dp[L][i] + dp[i + 1][R] + sum);
                    }
                }
            }
        }
        cout << dp[0][n - 1] << endl;
    }
}