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

// similar to tree diameter
int n, ans;
vector<vector<pair<int, int>>> adj;
vector<int> w, dp; // dp[i] = max ans in the subtree of i
void dfs(int curr, int par) {
    dp[curr] = w[curr];
    for(auto i : adj[curr]) {
        if(i.first == par) continue;
        dfs(i.first, curr);
    }
    int a = 0, b = 0;
    for(auto i : adj[curr]) {
        if(i.first == par) continue;
        int diff = dp[i.first] + w[curr] - i.second;
        if(diff >= a) {
            b = a;
            a = diff;
        } else if(diff >= b) b = diff;
    }
    dp[curr] = max(dp[curr], a);
    ans = max({ans, a, b, a + b - w[curr], w[curr]});
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        w.clear();
        w.resize(n + 1);
        dp.clear();
        dp.resize(n + 1);
        adj.clear();
        adj.resize(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> w[i];
        }
        for(int i=0;i<n-1;i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        ans = 0;
        dfs(1, 0);
        dbg(dp);
        cout << ans << endl;
    }
}