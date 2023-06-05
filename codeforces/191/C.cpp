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
 
#ifdef DEBUG
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
 
const int LOG = 22;
int n;
vector<vector<int>> up;
vector<vector<pair<int, int>>> adj;
vector<int> dist, vis, ans;
void fill0thParent(int curr, int par) {
    up[curr][0] = par;
    for(auto i : adj[curr]) {
        if(i.first == par) continue;
        fill0thParent(i.first, curr);
    }
}
void fillUpTable() {
    for(int j=1;j<LOG;j++) {
        for(int i=1;i<=n;i++) {
            int intermediate = up[i][j - 1];
            if(intermediate != -1) up[i][j] = up[intermediate][j - 1];
        }
    }
}
void calcDistFromRoot(int curr, int par, int lvl) {
    dist[curr] = lvl;
    for(auto i : adj[curr]) {
        if(i.first == par) continue;
        calcDistFromRoot(i.first, curr, lvl + 1);
    }
}
int kthParent(int node, int k) {
    for(int i=LOG-1;i>=0;i--) {
        if((k >> i) & 1) node = up[node][i];
    }
    return node;
}
int getLCA(int a, int b) {
    if(dist[a] > dist[b]) swap(a, b); // make sure b is always deeper
    b = kthParent(b, dist[b] - dist[a]);
    // now a and b are at same level
    if(a == b) return a; // edge case
    for(int i=LOG-1;i>=0;i--) {
        int par1 = up[a][i];
        int par2 = up[b][i];
        if(par1 != par2 && par1 != -1 && par2 != -1) {
            a = par1;
            b = par2;
        }
    }
    return up[a][0];
}
void dfs(int curr, int par) {
    for(auto i : adj[curr]) {
        if(i.first == par) continue;
        dfs(i.first, curr);
        vis[curr] += vis[i.first];
    }
}
void dfs2(int curr, int par) {
    for(auto i : adj[curr]) {
        if(i.first == par) continue;
        ans[i.second] = vis[i.first];
        dfs2(i.first, curr);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        adj.clear();
        adj.resize(n + 1);
        up.clear();
        up.resize(n + 1, vector<int>(LOG, -1));
        dist.clear();
        dist.resize(n + 1);
        vis.clear();
        vis.resize(n + 1);
        ans.clear();
        ans.resize(n);
        for(int i=1;i<n;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
        }
        fill0thParent(1, -1);
        fillUpTable();
        calcDistFromRoot(1, -1, 0);
        dbg(dist);
        dbg(up);
        int k;
        cin >> k;
        for(int i=1;i<=k;i++) {
            int a, b;
            cin >> a >> b;
            vis[a]++;
            vis[b]++;
            int lca = getLCA(a, b);
            dbg(a, b, lca);
            vis[lca] -= 2;
        }
        dfs(1, -1);
        dbg(vis);
        dfs2(1, -1);
        for(int i=1;i<n;i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}