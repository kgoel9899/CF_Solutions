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

int n, k;
vector<vector<int>> adj, dp;
vector<int> par;
void dfs(int curr, int p) {
    par[curr] = p;
    dp[curr][0] = 1;
    for(auto i : adj[curr]) {
        if(i == p) continue;
        dfs(i, curr);
    }
    for(auto i : adj[curr]) {
        if(i == p) continue;
        for(int j=1;j<=k;j++) {
            dp[curr][j] += dp[i][j - 1];
        }
    }
}
int solve(int curr, int kk) {
    int p = par[curr];
    if(p == 0) return 0;
    if(kk == 1) return 1;
    int ans = dp[p][kk - 1] - dp[curr][kk - 2];
    return ans + solve(p, kk - 1);
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> k;
        adj.clear();
        adj.resize(n + 1);
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(k == 1) {
            cout << n - 1 << endl;
            continue;
        }
        dp.clear();
        dp.resize(n + 1, vector<int>(k + 1));
        par.clear();
        par.resize(n + 1, -1);
        dfs(1, 0);
        dbg(dp);
        int ans = 0;
        for(int i=1;i<=n;i++) {
            ans += dp[i][k];
            ans += solve(i, k);
            dbg(i, ans);
        }
        cout << ans / 2 << endl;
    }
}