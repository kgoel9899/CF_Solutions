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
        int n;
        cin >> n;
        vector<set<int>> adj(n + 1);
        for(int i=0;i<n;i++) {
            int u, v;
            cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        vector<int> cnt(n + 1, 1);
        queue<int> q;
        for(int i=1;i<=n;i++) {
            if(adj[i].size() == 1) q.push(i);
        }
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            int par = *adj[f].begin();
            cnt[par] += cnt[f];
            cnt[f] = 0;
            adj[f].clear();
            adj[par].erase(f);
            if(adj[par].size() == 1) q.push(par);
        }
        int ans = 0;
        for(int i=1;i<=n;i++) {
            ans += (cnt[i] * (cnt[i] - 1)) / 2 + cnt[i] * (n - cnt[i]);
        }
        cout << ans << endl;
    }
}