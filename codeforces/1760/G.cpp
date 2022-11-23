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

int n, a, b;
vector<vector<pair<int, int>>> adj;
set<int> s, s2;
void dfs(int curr, int par, int xr) {
    for(auto& i : adj[curr]) {
        if(i.first == par) continue;
        s.insert(xr ^ i.second);
        dfs(i.first, curr, xr ^ i.second);
    }
}
void dfs2(int curr, int par, int xr) {
    s2.insert(xr);
    for(auto& i : adj[curr]) {
        if(i.first == par || i.first == b) continue;
        dfs2(i.first, curr, xr ^ i.second);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n >> a >> b;
        adj.clear();
        adj.resize(n + 1);
        for(int i=0;i<n-1;i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        s.clear();
        s2.clear();
        dfs(b, -1, 0);
        dbg(s);
        dfs2(a, -1, 0);
        dbg(s2);
        int done = 0;
        for(auto i : s2) {
            if(s.find(i) != s.end()) {
                done = 1;
                break;
            }
        }
        if(done) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}