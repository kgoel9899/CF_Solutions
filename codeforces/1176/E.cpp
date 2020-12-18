#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 2e5 + 5;
vector<int> col(N, -1);
vector<vector<int>> adj(N);
void dfs(int curr, int c) {
    col[curr] = c;
    c ^= 1;
    for(auto i : adj[curr]) {
        if(col[i] != -1) continue;
        dfs(i, c);
    }
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i=1;i<=n;i++) {
            adj[i].clear();
            col[i] = -1;
        }
        for(int i=0;i<m;i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0);
        int zero = 0;
        for(int i=1;i<=n;i++) {
            if(col[i] == 0) zero++;
        }
        if(zero <= n / 2) {
            cout << zero << endl;
            for(int i=1;i<=n;i++) {
                if(col[i] == 0) cout << i << " ";
            }
            cout << endl;
        } else {
            cout << n - zero << endl;
            for(int i=1;i<=n;i++) {
                if(col[i] == 1) cout << i << " ";
            }
            cout << endl;
        }
    }
}