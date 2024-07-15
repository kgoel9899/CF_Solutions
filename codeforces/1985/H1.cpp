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

class DSU {
    int N;
    vector<int> par, sz;
    public:
    DSU(int n) {
        N = n;
        par.resize(n);
        sz.resize(n);
        make_set();
    }
    void make_set() {
        for(int i=0;i<N;i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find_set(int u) {
        if(par[u] == u) return u;
        return par[u] = find_set(par[u]);
    }
    void union_sets(int u, int v) {
        dbg(u, v);
        u = find_set(u);
        v = find_set(v);
        if(u == v) return;
        if(sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
    int get_size(int u) {
        return sz[find_set(u)];
    }
};
void dfs(int i, int j, int pi, int pj, int n, int m, vector<string>& v, vector<vector<bool>>& vis, DSU& dsu) {
    if(i >= n || i < 0 || j >= m || j < 0 || vis[i][j] || v[i][j] != '#') return;
    vis[i][j] = true;
    if(pi != -1) {
        dbg(i, j, pi, pj);
        dsu.union_sets(i * m + j, pi * m + pj);
    }
    dfs(i + 1, j, i, j, n, m, v, vis, dsu);
    dfs(i - 1, j, i, j, n, m, v, vis, dsu);
    dfs(i, j + 1, i, j, n, m, v, vis, dsu);
    dfs(i, j - 1, i, j, n, m, v, vis, dsu);
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int tot = n * m;
        DSU dsu(tot);
        vector<vector<bool>> vis(n, vector<bool>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j]) continue;
                if(v[i][j] != '#') continue;
                dfs(i, j, -1, -1, n, m, v, vis, dsu);
                // dbg(i, j, dsu.get_size(i * m + j));
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            set<int> done;
            int dots = 0;
            for(int j=0;j<m;j++) {
                if(v[i][j] == '#') done.insert(dsu.find_set(i * m + j));
                else {
                    if(i >= 1) {
                        if(v[i - 1][j] == '#') done.insert(dsu.find_set((i - 1) * m + j));
                    }
                    if(i <= n - 2) {
                        if(v[i + 1][j] == '#') done.insert(dsu.find_set((i + 1) * m + j));
                    }
                    dots++;
                }
            }
            int curr = 0;
            for(auto& j : done) {
                curr += dsu.get_size(j);
            }
            dbg(i, done, curr);
            ans = max(ans, curr + dots);
        }
        for(int j=0;j<m;j++) {
            set<int> done;
            int dots = 0;
            for(int i=0;i<n;i++) {
                if(v[i][j] == '#') done.insert(dsu.find_set(i * m + j));
                else {
                    if(j >= 1) {
                        if(v[i][j - 1] == '#') done.insert(dsu.find_set(i * m + j - 1));
                    }
                    if(j <= m - 2) {
                        if(v[i][j + 1] == '#') done.insert(dsu.find_set(i * m + j + 1));
                    }
                    dots++;
                }
            }
            int curr = 0;
            for(auto& i : done) {
                curr += dsu.get_size(i);
            }
            ans = max(ans, curr + dots);
        }
        cout << ans << endl;
    }
}