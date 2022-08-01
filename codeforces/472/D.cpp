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

// MST
int n;
vector<vector<int>> adj;
vector<vector<pair<int, int>>> graph;
vector<int> par, sz, dist;
void make_set(int u) {
    par[u] = u;
    sz[u] = 1;
}
int find_set(int u) {
    if(par[u] == u) return u;
    return par[u] = find_set(par[u]);
}
void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if(u == v) return;
    if(sz[v] < sz[u]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}
void dfs(int curr, int p, int d) {
    dist[curr] = d;
    for(auto i : graph[curr]) {
        if(i.first == p) continue;
        dfs(i.first, curr, d + i.second);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        adj.clear();
        adj.resize(n, vector<int>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> adj[i][j];
            }
        }
        par.clear();
        par.resize(n);
        sz.clear();
        sz.resize(n);
        for(int i=0;i<n;i++) {
            make_set(i);
        }
        int ok = 1;
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i == j) continue;
                if(adj[i][j] == 0) ok = 0;
                edges.push_back({adj[i][j], {i, j}});
            }
        }
        if(!ok) {
            cout << "NO" << endl;
            continue;
        }
        sort(all(edges));
        dbg(edges);
        graph.clear();
        graph.resize(n);
        for(auto i : edges) {
            if(find_set(i.second.first) == find_set(i.second.second)) continue;
            union_sets(i.second.first, i.second.second);
            graph[i.second.first].push_back({i.second.second, i.first});
            graph[i.second.second].push_back({i.second.first, i.first});
        }
        dbg(graph);
        dist.clear();
        dist.resize(n);
        for(int i=0;i<n;i++) {
            fill(all(dist), 0);
            dfs(i, -1, 0);
            for(int j=0;j<n;j++) {
                if(dist[j] != adj[i][j]) ok = 0;
            }
            if(!ok) break;
        }
        if(ok) cout << "YES" << endl;
        else  cout << "NO" << endl;
    }
}