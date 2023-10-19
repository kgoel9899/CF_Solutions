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
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> x(n + 1), y(n + 1), c(n + 1), k(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> x[i] >> y[i];
        }
        for(int i=1;i<=n;i++) {
            cin >> c[i];
        }
        for(int i=1;i<=n;i++) {
            cin >> k[i];
        }
        vector<vector<int>> adj;
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                int cost = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
                adj.push_back({cost, i, j});
            }
            adj.push_back({c[i], i, 0});
        }
        sort(all(adj));
        dbg(adj);
        par.clear();
        par.resize(n + 1);
        sz.clear();
        sz.resize(n + 1);
        for(int i=1;i<=n;i++) {
            make_set(i);
        }
        int tot = 0;
        vector<int> stations;
        vector<pair<int, int>> conns;
        for(auto& i : adj) {
            if(find_set(i[1]) == find_set(i[2])) continue;
            union_sets(i[1], i[2]);
            tot += i[0];
            if(i[2] == 0) stations.push_back(i[1]);
            else {
                assert(i[1] != 0);
                conns.push_back({i[1], i[2]});
            }
        }
        cout << tot << endl;
        cout << stations.size() << endl;
        for(auto& i : stations) {
            cout << i << " ";
        }
        cout << endl;
        cout << conns.size() << endl;
        for(auto& i : conns) {
            cout << i.first << " " << i.second << endl;
        }
    }
}