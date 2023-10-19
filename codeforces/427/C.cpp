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
vector<int> v, order, vis, comp;
vector<vector<int>> adj, adj_rev;
void dfs1(int curr) {
    vis[curr] = 1;
    for(auto& i : adj[curr]) {
        if(!vis[i]) dfs1(i);
    }
    order.push_back(curr);
}
void dfs2(int curr) {
    vis[curr] = 1;
    comp.push_back(curr);
    for(auto& i : adj_rev[curr]) {
        if(!vis[i]) dfs2(i);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        v.clear();
        v.resize(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> v[i];
        }
        cin >> m;
        adj.clear();
        adj.resize(n + 1);
        adj_rev.clear();
        adj_rev.resize(n + 1);
        for(int i=0;i<m;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj_rev[b].push_back(a);
        }
        order.clear();
        vis.clear();
        vis.resize(n + 1);
        for(int i=1;i<=n;i++) {
            if(!vis[i]) dfs1(i);
        }
        reverse(all(order));
        dbg(order);
        vis.clear();
        vis.resize(n + 1);
        comp.clear();
        dbg(adj_rev);
        int cost = 0, ways = 1;
        for(auto& i : order) {
            if(!vis[i]) {
                dfs2(i);
                dbg(comp);
                int mn = INF, ct = 0;
                for(auto& j : comp) {
                    if(v[j] < mn) {
                        mn = v[j];
                        ct = 1;
                    } else if(v[j] == mn) ct++;
                }
                cost += mn;
                ways *= ct;
                ways %= MOD;
                comp.clear();
            }
        }
        cout << cost << " " << ways << endl;
    }
}  