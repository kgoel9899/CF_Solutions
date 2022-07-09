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
vector<vector<int>> adj;
vector<int> sub, dp; // dp[i] = ans only considering subtree of i
void dfs(int curr, int par) {
    sub[curr] = 1;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr);
        sub[curr] += sub[i];
        dp[curr] += dp[i];
    }
    dp[curr] += sub[curr];
}
void dfs2(int curr, int par) {
    for(auto i : adj[curr]) {
        if(i == par) continue;
        int valPar = dp[curr] - dp[i] - sub[i];
        int valChildren = dp[i] - sub[i];
        if(i == 2) dbg(valPar, valChildren, n);
        dp[i] = valPar + valChildren + n;
        if(i == 2) dbg(dp[i]);
        dfs2(i, curr);
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
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        sub.clear();
        sub.resize(n + 1);
        dp.clear();
        dp.resize(n + 1);
        dfs(1, 0);
        dbg(dp);
        dfs2(1, 0);
        dbg(dp);
        int ans = 0;
        for(auto i : dp) {
            ans = max(ans, i);
        }
        cout << ans << endl;
    }
}

// 5 + 3 + 1 + 1 + 1 = 11

// 5 + 2 + 1 + 1 + 1 = 10

// 5 + 4 + 3 + 1 + 1 = 14