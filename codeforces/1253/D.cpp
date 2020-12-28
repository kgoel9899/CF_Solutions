#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 2e5 + 5;
vector<vector<int>> adj(N);
vector<int> vis(N);
int mx = 0;
void dfs(int curr) {
    vis[curr] = 1;
    mx = max(mx, curr);
    for(auto i : adj[curr]) {
        if(vis[i] == 0) dfs(i);
    }
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i=0;i<m;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = 0;
        for(int i=1;i<=n;i++) {
            if(vis[i] == 0) {
                if(i < mx) ans++;
                dfs(i);
            }
        }
        cout << ans << endl;
    }
}