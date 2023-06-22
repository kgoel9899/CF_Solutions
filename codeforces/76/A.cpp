#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = LLONG_MAX;

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
int G, S;
vector<int> par, sz;
vector<vector<int>> curr;
void make_set(int u) {
    sz[u] = 1;
    par[u] = u;
}
int find_set(int u) {
    if(par[u] == u) return u;
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
bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
int solve() {
    sort(all(curr), compare);
    par.clear();
    par.resize(n + 1);;
    sz.clear();
    sz.resize(n + 1);
    for(int i=1;i<=n;i++) {
        make_set(i);
    }
    int here = 0, ct = 0;
    vector<vector<int>> temp;
    for(auto& i : curr) {
        if(find_set(i[2]) != find_set(i[3])) {
            union_sets(i[2], i[3]);
            here = max(here, i[1]);
            temp.push_back(i);
            ct++;
        }
    }
    curr = temp;
    // if(G == 1000000000) cout << ct << "#";
    if(ct != n - 1) return INF;
    return here;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> m;
        cin >> G >> S;
        vector<vector<int>> edges;
        for(int i=0;i<m;i++) {
            int x, y, g, s;
            cin >> x >> y >> g >> s;
            edges.push_back({g, s, x, y});
        }
        sort(all(edges));
        dbg(edges);
        curr.clear();
        int ans = INF;
        for(auto& i : edges) {
            curr.push_back(i);
            // dbg(solve());
            dbg(G, S);
            dbg(i[0]);
            // dbg(G * i[0] + S * solve());
            int ss = solve();
            if(ss == INF) continue;
            // if(G == 1000000000) assert(0);
            ans = min(ans, G * i[0] + S * ss);
            dbg(ans);
        }
        if(ans == INF) ans = -1;
        cout << ans << endl;
    }
}