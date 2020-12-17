#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 1e5 + 5;
vector<vector<int>> adj(N);
vector<vector<int>> dp(N, vector<int>(2, 1));
void dfs(int curr, int par) {
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr);
        dp[curr][0] *= dp[i][1];
        dp[curr][0] %= MOD;
        dp[curr][1] *= (dp[i][0] + dp[i][1]) % MOD;
        dp[curr][1] %= MOD;
    }
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=0;i<n-1;i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0);
        cout << (dp[1][0] + dp[1][1]) % MOD << endl;
    }
}