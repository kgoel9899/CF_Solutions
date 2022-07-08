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

int n;
vector<vector<pair<int, int>>> adj;
vector<int> dp;
void dfs(int curr, int par) {
    for(auto i : adj[curr]) {
        if(i.first == par) continue;
        dfs(i.first, curr);
        if(i.second == 0) dp[curr]++;
        dp[curr] += dp[i.first];
    }
}
void dfs2(int curr, int par) {
    for(auto i : adj[curr]) {
        if(i.first == par) continue;
        dp[i.first] = dp[curr];
        if(i.second == 0) dp[i.first]--;
        else dp[i.first]++;
        dfs2(i.first, curr);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        adj.clear();
        adj.resize(n + 1);
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back({b, 1}); // 1 = valid
            adj[b].push_back({a, 0}); // 0 = invalid
        }
        dp.clear();
        dp.resize(n + 1);
        dfs(1, 0);
        int ans = INF;
        dbg(dp);
        dfs2(1, 0);
        dbg(dp);
        for(int i=1;i<=n;i++) {
            ans = min(ans, dp[i]);
        }
        cout << ans << endl;
        for(int i=1;i<=n;i++) {
            if(dp[i] == ans) cout << i << " ";
        }
        cout << endl;
    }
}