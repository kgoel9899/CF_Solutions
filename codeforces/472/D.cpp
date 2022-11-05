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
vector<vector<int>> v;
vector<int> par, sz;
vector<vector<pair<int, int>>> adj;
void make_set(int u) {
    par[u] = u;
    sz[u] = 1;
}
int find_set(int u) {
    if(u == par[u]) return u;
    return par[u] = find_set(par[u]);
}
void union_sets(int u, int vv) {
    u = find_set(u);
    vv = find_set(vv);
    if(u == vv) return;
    if(sz[u] < sz[vv]) swap(u, vv);
    par[vv] = u;
    sz[u] += sz[vv];
}
void dfs(int curr, int parent, int d, vector<int>& dist) {
    dist[curr] = d;
    for(auto i : adj[curr]) {
        if(i.first == parent) continue;
        dfs(i.first, curr, d + i.second, dist);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        v.clear();
        v.resize(n + 1, vector<int>(n + 1));
        par.clear();
        par.resize(n + 1);
        sz.clear();
        sz.resize(n + 1);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cin >> v[i][j];
            }
        }
        int ok = 1;
        vector<vector<int>> edges;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                if(i == j) {
                    if(v[i][j] != 0) {
                        ok = 0;
                        break;
                    }
                    continue;
                }
                if(v[i][j] != v[j][i] || v[i][j] == 0) {
                    ok = 0;
                    break;
                }
                edges.push_back({v[i][j], i, j});
            }
        }
        if(!ok) {
            cout << "NO" << endl;
            continue;
        }
        for(int i=1;i<=n;i++) {
            make_set(i);
        }
        sort(all(edges));
        adj.clear();
        adj.resize(n + 1);
        for(auto i : edges) {
            int d = i[0], u = i[1], vv = i[2];
            int p1 = find_set(u);
            int p2 = find_set(vv);
            if(p1 == p2) continue;
            union_sets(u, vv);
            adj[u].push_back({vv, d});
            adj[vv].push_back({u, d});
        }
        dbg(adj);
        for(int i=1;i<=n;i++) {
            vector<int> dist(n + 1);
            dfs(i, -1, 0, dist);
            for(int j=1;j<=n;j++) {
                if(v[i][j] != dist[j]) {
                    ok = 0;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}