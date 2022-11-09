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

vector<int> par, sz;
void make_set(int u) {
    par[u] = u;
    sz[u] = 1;
}
int find_set(int u) {
    if(u == par[u]) return u;
    return par[u] = find_set(par[u]);
}
void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if(u == v) return;
    if(sz[v] < sz[u]) swap(u, v);
    sz[u] += sz[v];
    par[v] = par[u];
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        par.clear();
        par.resize(n + 1);
        sz.clear();
        sz.resize(n + 1);
        for(int i=1;i<=n;i++) {
            int num;
            cin >> num;
            make_set(i);
        }
        int m;
        cin >> m;
        vector<pair<int, pair<int, int>>> edges;
        while(m--) {
            int a, b, c;
            cin >> a >> b >> c;
            edges.push_back({c, {a, b}});
        }
        sort(all(edges));
        dbg(edges);
        vector<int> sup(n + 1);
        int ans = 0;
        for(auto& i : edges) {
            int w = i.first;
            int a = i.second.first;
            int b = i.second.second;
            if(find_set(a) == find_set(b) || sup[b]) continue;
            ans += w;
            union_sets(a, b);
            sup[b] = 1;
        }
        set<int> check;
        for(int i=1;i<=n;i++) {
            check.insert(find_set(i));
        }
        if(check.size() == 1) cout << ans << endl;
        else cout << -1 << endl;
    }
}