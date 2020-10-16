#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int N = 2e5 + 10;
vector<int> v(N), val(N);
vector<vector<int>> adj(N);
int rootAns = 0, ans = 0;
void dfs(int curr, int par, int depth) {
    val[curr] = v[curr];
    for(auto i : adj[curr]) {
        if(i == par) continue;
        rootAns += depth * v[i];
        dfs(i, curr, depth + 1);
        val[curr] += val[i];
    }
}
void dfs2(int curr, int par) {
    ans = max(ans, rootAns);
    for(auto i : adj[curr]) {
        if(i == par) continue;
        rootAns -= val[i];
        val[curr] -= val[i];
        val[i] += val[curr];
        rootAns += val[curr];
        dfs2(i, curr);
        rootAns -= val[curr];
        val[i] -= val[curr];
        val[curr] += val[i];
        rootAns += val[i];
    }
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=1;i<=n;i++) {
            cin >> v[i];
        }
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0, 1);
        dfs2(1, 0);
        cout << ans << endl;
    }
}