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

int n, m, timer, ans;
vector<bool> vis;
vector<int> tin, low;
vector<vector<int>> adj;
set<pair<int, int>> bridges;
void bridgeDfs(int curr, int par) {
    vis[curr] = true;
    tin[curr] = low[curr] = timer++;
    for(auto& to : adj[curr]) {
        if(to == par) continue;
        if(vis[to]) low[curr] = min(low[curr], tin[to]);
        else {
            bridgeDfs(to, curr);
            low[curr] = min(low[curr], low[to]);
            if(low[to] > tin[curr]) {
                bridges.insert({to, curr});
                bridges.insert({curr, to});
            }
        }
    }
}
int dfs(int curr) {
    vis[curr] = true;
    int tot = 1;
    for(auto& to : adj[curr]) {
        if(vis[to]) continue;
        int sub = dfs(to);
        tot += sub;
        if(bridges.find({curr, to}) != bridges.end()) {
            dbg(curr, to, sub);
            ans = max(ans, sub * (n - sub));
        }
    }
    return tot;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n >> m;
        adj.clear();
        adj.resize(n + 1);
        for(int i=0;i<m;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        timer = 0;
        vis.clear();
        vis.resize(n + 1);
        tin.clear();
        tin.resize(n + 1);
        low.clear();
        low.resize(n + 1);
        bridges.clear();
        bridgeDfs(1, -1);
        dbg(bridges);
        ans = 0;
        vis.clear();
        vis.resize(n + 1);
        dfs(1);
        cout << n * (n - 1) / 2 - ans << endl;
    }
}