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
 
int n, q;
const int LOG = 25;
vector<vector<int>> adj, up;
vector<int> dist;
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
int solve(int f, int s, int t) {
    int lca1 = getLCA(f, s);
    int lca2 = getLCA(f, t);
    bool cond1 = lca1 == f;
    bool cond2 = lca2 == f;
    if(cond1 != cond2) {
        // one of them is outside f's subtree
        return 1;
    } else {
        if(cond1) {
            // s, t lie in f's subtree
            return dist[getLCA(s, t)] - dist[f] + 1;
        } else {
            if(lca1 != lca2) return dist[f] - max(dist[lca1], dist[lca2]) + 1;
            else return dist[getLCA(s, t)] + dist[f] - 2 * dist[lca1] + 1;
        }
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> q;
        adj.clear();
        adj.resize(n + 1);
        for(int i=2;i<=n;i++) {
            int a;
            cin >> a;
            adj[a].push_back(i);
            adj[i].push_back(a);
        }
        dist.clear();
        dist.resize(n + 1);
        up.clear();
        up.resize(n + 1, vector<int>(LOG, -1));
        dfs(1, -1, 0);
        fillUpTable();
        while(q--) {
            vector<int> v(3);
            cin >> v[0] >> v[1] >> v[2];
            int ans = 0;
            for(int i=0;i<3;i++) {
                int f = v[i];
                int s = v[(i + 1) % 3];
                int t = v[(i + 2) % 3];
                ans = max(ans, solve(f, s, t));
            }
            cout << ans << endl;
        }
    }
}