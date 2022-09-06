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

const int LOG = 32;
int n;
vector<vector<int>> adj, up;
vector<int> tin, tout, dist;
int timer;
void dfs(int curr, int par, int lvl) {
    dist[curr] = lvl;
    tin[curr] = timer++;
    up[curr][0] = par;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr, lvl + 1);
    }
    tout[curr] = timer++;
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
bool compare(int a, int b) {
    return dist[a] > dist[b];
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
        for(int i=0;i<n-1;i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        tin.clear();
        tin.resize(n + 1);
        tout.clear();
        tout.resize(n + 1);
        dist.clear();
        dist.resize(n + 1);
        timer = 0;
        dfs(1, -1, 0);
        fillUpTable();
        int q;
        cin >> q;
        while(q--) {
            int k;
            cin >> k;
            vector<int> v(k);
            for(int i=0;i<k;i++) {
                cin >> v[i];
            }
            sort(all(v), compare);
            dbg(v);
            int one = v[0], two = -1, lca = -1;
            int ok = 1;
            for(int i=1;i<k;i++) {
                int node = v[i];
                if(two == -1) {
                    if(tin[node] < tin[one] && tout[one] < tout[node]) continue;
                    two = node;
                    lca = getLCA(one, two);
                    dbg(lca);
                } else {
                    dbg(node);
                    assert(lca != -1);
                    if(tin[lca] <= tin[node] && tout[node] <= tout[lca]) {
                        // node lies below lca
                        if((tin[node] < tin[one] && tout[one] < tout[node]) || (tin[node] < tin[two] && tout[two] < tout[node])) {
                            // node lies between one to lca or between two to lca
                            continue;
                        }
                    }
                    ok = 0;
                    break;
                }
            }
            if(ok) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}