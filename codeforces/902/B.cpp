#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
int ans = 0;
void dfs(vector<vector<int>>& adj, vector<int>& col, int curr, int par, int cl) {
    for(auto i : adj[curr]) {
        if(i == par) continue;
        if(col[i] == cl) dfs(adj, col, i, curr, cl);
        else {
            ans++;
            dfs(adj, col, i, curr, col[i]);
        }
    }
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for(int i=2;i<=n;i++) {
            int p;
            cin >> p;
            adj[p].push_back(i);
            adj[i].push_back(p);
        }
        vector<int> col(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> col[i];
        }
        dfs(adj, col, 1, 0, col[1]);
        cout << ans + 1 << endl;
    }
}