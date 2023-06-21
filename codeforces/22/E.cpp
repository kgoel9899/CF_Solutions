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

// SCC
int n, m;
vector<int> order, vis, roots, leaf, source;
set<int> heads;
vector<vector<int>> adj, adj_rev, adj_scc, all_leaves;
void dfs(int curr) {
    vis[curr] = 1;
    for(auto& i : adj[curr]) {
        if(vis[i]) continue;
        dfs(i);
    }
    order.push_back(curr);
}
void dfs2(int curr, int root) {
    vis[curr] = 1;
    roots[curr] = root;
    for(auto& i : adj_rev[curr]) {
        if(vis[i]) continue;
        dfs2(i, root);
    }
}
void dfs3(int curr) {
    int ch = 0;
    for(auto& i : adj_scc[curr]) {
        dfs3(i);
        ch = 1;
    }
    if(!ch) leaf.push_back(curr);
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        adj.clear();
        adj.resize(n + 1);
        adj_rev.clear();
        adj_rev.resize(n + 1);
        for(int i=1;i<=n;i++) {
            int a;
            cin >> a;
            adj[i].push_back(a);
            adj_rev[a].push_back(i);
        }
        vis.clear();
        vis.resize(n + 1);
        order.clear();
        for(int i=1;i<=n;i++) {
            if(!vis[i]) dfs(i);
        }
        reverse(all(order));
        dbg(order);
        vis.clear();
        vis.resize(n + 1);
        roots.clear();
        roots.resize(n + 1);
        heads.clear();
        for(auto& i : order) {
            if(!vis[i]) {
                heads.insert(i);
                dfs2(i, i);
            }
        }
        dbg(heads);
        dbg(roots);
        if(heads.size() == 1) {
            cout << 0 << endl;
            continue;
        }
        adj_scc.clear();
        adj_scc.resize(n + 1);
        for(int i=1;i<=n;i++) {
            for(auto& j : adj[i]) {
                int x = roots[i], y = roots[j];
                if(x != y) adj_scc[x].push_back(y);
            }
        }
        dbg(adj_scc);
        vector<int> in(n + 1, -1);
        for(int i=1;i<=n;i++) {
            for(auto& j : adj_scc[i]) {
                assert(i != j);
                if(in[i] == -1) in[i] = 0;
                if(in[j] == -1) in[j] = 0;
                in[j]++;
            }
        }
        dbg(in);
        source.clear();
        all_leaves.clear();
        set<int> head_set(all(heads));
        for(int i=1;i<=n;i++) {
            if(in[i] == 0 || (in[i] == -1 && head_set.find(i) != head_set.end())) {
                leaf.clear();
                source.push_back(i);
                dfs3(i);
                dbg(leaf);
                all_leaves.push_back(leaf);
            }
        }
        dbg(source);
        dbg(all_leaves);
        int sz = source.size();
        vector<pair<int, int>> ans;
        for(int i=0;i<sz;i++) {
            for(auto& j : all_leaves[i]) {
                ans.push_back({j, source[(i + 1) % sz]});
            }
        }
        cout << ans.size() << endl;
        for(auto& i : ans) {
            cout << i.first << " " << i.second << endl;
        }
    }
}