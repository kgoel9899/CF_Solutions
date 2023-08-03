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

int n, m;
vector<int> vis, dist;
vector<vector<pair<int, int>>> adj;
void dfs(int curr) {
    vis[curr] = 1;
    for(auto& i : adj[curr]) {
        if(vis[i.first]) continue;
        dist[i.first] = dist[curr] + i.second;
        dfs(i.first);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n >> m;
        adj.clear();
        adj.resize(n + 1);
        vis.clear();
        vis.resize(n + 1);
        dist.clear();
        dist.resize(n + 1);
        vector<vector<int>> conds;
        for(int i=0;i<m;i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, -c});
            conds.push_back({a, b, c});
        }
        for(int i=1;i<=n;i++) {
            if(!vis[i]) dfs(i);
        }
        int ok = 1;
        for(auto& i : conds) {
            if(dist[i[0]] + i[2] != dist[i[1]]) {
                ok = 0;
                break;
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}