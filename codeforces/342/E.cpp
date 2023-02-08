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

int n, m;
const int LOG = 25;
vector<vector<int>> up;
vector<int> dist, sub, cent_par, best;
vector<set<int>> adj;
int ct, root;
void dfs(int curr, int par, int d) {
    dist[curr] = d;
    up[curr][0] = par;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr, d + 1);
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
int kthParent(int node, int k) {
    for(int i=LOG-1;i>=0;i--) {
        if(node == -1) break;
        if(((k >> i) & 1) == 1) node = up[node][i];
    }
    return node;
}
int getLCA(int a, int b) {
    if(dist[a] > dist[b]) swap(a, b);
    b = kthParent(b, dist[b] - dist[a]);
    if(a == b) return a;
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
int getDistance(int u, int v) {
    int lca = getLCA(u, v);
    return dist[u] + dist[v] - 2 * dist[lca];
}
void dfs1(int curr, int par) {
    sub[curr] = 1;
    ct++;
    for(auto& i : adj[curr]) {
        if(i == par) continue;
        dfs1(i, curr);
        sub[curr] += sub[i];
    }
}
int dfs2(int curr, int par) {
    for(auto& i : adj[curr]) {
        if(i == par) continue;
        if(sub[i] > ct / 2) return dfs2(i, curr);
    }
    return curr;
}
void decompose(int curr, int cent) {
    ct = 0;
    dfs1(curr, -1);
    int centroid = dfs2(curr, -1);
    cent_par[centroid] = cent;
    if(cent == -1) root = centroid;
    for(auto& i : adj[centroid]) {
        adj[i].erase(centroid);
        decompose(i, centroid);
    }
}
void update(int u) {
    best[u] = 0;
    int curr = cent_par[u];
    while(curr != -1) {
        best[curr] = min(best[curr], getDistance(curr, u));
        curr = cent_par[curr];
    }
}
int query(int u) {
    int ans = best[u];
    int curr = cent_par[u];
    while(curr != -1) {
        ans = min(ans, best[curr] + getDistance(curr, u));
        curr = cent_par[curr];
    }
    return ans;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> m;
        dist.clear();
        dist.resize(n + 1);
        sub.clear();
        sub.resize(n + 1);
        adj.clear();
        adj.resize(n + 1);
        cent_par.clear();
        cent_par.resize(n + 1, -1);
        up.clear();
        up.resize(n + 1, vector<int>(LOG, -1));
        best.clear();
        best.resize(n + 1, INF);
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        dfs(1, -1, 0);
        fillUpTable(); // up table of original tree works because we are calculating distances, if we want something else it will not work and we will have to make the up table for the centroid tree
        decompose(1, -1);
        dbg(root);
        dbg(cent_par);
        update(1);
        for(int i=0;i<m;i++) {
            int t, node;
            cin >> t >> node;
            if(t == 1) update(node);
            else cout << query(node) << endl;
        }
    }
}