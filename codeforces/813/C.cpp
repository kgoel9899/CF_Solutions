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

int n, x, ans;
vector<int> a, b, sub, mx, parent;
vector<vector<int>> adj;
void dfs1(int curr, int par, int d) {
    a[curr] = d;
    mx[curr] = curr;
    parent[curr] = par;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs1(i, curr, d + 1);
        if(1 + sub[i] > sub[curr]) {
            sub[curr] = 1 + sub[i];
            mx[curr] = mx[i];
        }
    }
}
void dfs2(int curr, int par, int d) {
    b[curr] = d;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs2(i, curr, d + 1);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> x;
        adj.clear();
        adj.resize(n + 1);
        for(int i=0;i<n-1;i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        a.clear();
        a.resize(n + 1);
        b.clear();
        b.resize(n + 1);
        sub.clear();
        sub.resize(n + 1);
        mx.clear();
        mx.resize(n + 1);
        parent.clear();
        parent.resize(n + 1);
        dfs1(1, 0, 0);
        dfs2(x, 0, 0);
        int up = (a[x] - 1) / 2;
        ans = up; // for bob
        while(up > 0) {
            x = parent[x];
            up--;
        }
        dbg(x);
        ans += a[mx[x]] - a[x]; // for bob
        int alice = a[mx[x]];
        ans += (alice - ans);
        ans += alice;
        cout << ans << endl;
    }
}