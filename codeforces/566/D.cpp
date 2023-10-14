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
    if(par[u] == u) return u;
    return par[u] = find_set(par[u]);
}
void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        par.clear();
        par.resize(n + 1);
        sz.clear();
        sz.resize(n + 1);
        set<int> s;
        for(int i=1;i<=n;i++) {
            make_set(i);
            s.insert(i);
        }
        while(q--) {
            int t, x, y;
            cin >> t >> x >> y;
            if(t == 1) union_sets(x, y);
            else if(t == 2) {
                while(true) {
                    auto it = s.lower_bound(x);
                    if(it == s.end() || *it > y) break;
                    union_sets(*it, y);
                    dbg(*it, y);
                    if(*it == y) break;
                    s.erase(*it);
                }
                dbg(s);
            } else {
                if(find_set(x) == find_set(y)) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }
}