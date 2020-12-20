#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 2e6 + 5;
vector<int> dp(N);
void helper() {
    for(int i=2;i<N;i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
        dp[i] %= MOD;
        if(i % 3 == 0) dp[i] += 4;
        dp[i] %= MOD;
    }
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    helper();
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}