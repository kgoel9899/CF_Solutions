#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int N = 2e5 + 10;
vector<vector<int>> adj(N);
vector<int> tot(N), dp(N);
int ans = 0;
void dfs(int curr, int par) {
    tot[curr] = 1;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr);
        tot[curr] += tot[i];
    }
}
void dfs2(int curr, int par) {
    dp[curr] = tot[curr];
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs2(i, curr);
        dp[curr] += dp[i];
    }
}
void dfs3(int curr, int par) {
    ans = max(ans, dp[curr]);
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dp[curr] -= dp[i];
        dp[curr] -= tot[i];
        tot[curr] -= tot[i];
        dp[i] += tot[curr];
        dp[i] += dp[curr];
        tot[i] += tot[curr];
        dfs3(i, curr);
        tot[i] -= tot[curr];
        dp[i] -= dp[curr];
        dp[i] -= tot[curr];
        tot[curr] += tot[i];
        dp[curr] += tot[i];
        dp[curr] += dp[i];
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
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0);
        dfs2(1, 0);
        dfs3(1, 0);
        cout << ans << endl;
    }
}