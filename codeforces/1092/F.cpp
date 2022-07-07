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

int n, tot;
vector<int> v, sub, dp;
vector<vector<int>> adj;
void dfs(int curr, int par, int lvl) {
    sub[curr] = v[curr];
    dp[1] += v[curr] * lvl;
    dbg(curr, v[curr], lvl);
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr, lvl + 1);
        sub[curr] += sub[i];
    }
}
void dfs2(int curr, int par) {
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dp[i] = dp[curr] - sub[i] + (tot - sub[i]);
        dfs2(i, curr);
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
        sub.clear();
        sub.resize(n + 1);
        dp.clear();
        dp.resize(n + 1);
        adj.clear();
        adj.resize(n + 1);
        tot = 0;
        for(int i=1;i<=n;i++) {
            cin >> v[i];
            tot += v[i];
        }
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dbg(adj);
        dfs(1, 0, 0);
        dbg(dp);
        dbg(sub);
        dfs2(1, 0);
        dbg(dp);
        int ans = 0;
        for(int i=1;i<=n;i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
}