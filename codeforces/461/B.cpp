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

// https://abitofcs.blogspot.com/2014/12/dynamic-programming-on-tree-forming-up.html
int n;
vector<vector<int>> adj, dp;
vector<int> col;
void dfs(int curr, int par) {
    if(col[curr] == 1) dp[curr][1] = 1;
    else dp[curr][0] = 1;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr);
        int black = dp[curr][1];
        int white = dp[curr][0];
        
        // include i
        dp[curr][1] = black * dp[i][0] + white * dp[i][1];
        dp[curr][1] %= MOD;
        dp[curr][0] = white * dp[i][0];
        dp[curr][0] %= MOD;
        
        // exclude i
        dp[curr][1] += black * dp[i][1];
        dp[curr][1] %= MOD;
        dp[curr][0] += white * dp[i][1];
        dp[curr][0] %= MOD;
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        adj.clear();
        adj.resize(n);
        for(int i=0;i<n-1;i++) {
            int a;
            cin >> a;
            adj[a].push_back(i + 1);
            adj[i + 1].push_back(a);
        }
        col.clear();
        col.resize(n);
        for(int i=0;i<n;i++) {
            cin >> col[i];
        }
        dp.clear();
        dp.resize(n, vector<int>(2));
        dfs(0, -1);
        cout << dp[0][1] << endl;
    }
}