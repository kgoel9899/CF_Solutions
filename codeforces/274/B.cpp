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
vector<vector<int>> adj, dp;
vector<int> v;
void dfs(int curr, int par) {
    int inc = 0, dec = 0;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr);
        inc = max(inc, dp[i][0]);
        dec = max(dec, dp[i][1]);
    }
    v[curr] += inc;
    v[curr] -= dec;
    if(v[curr] < 0) inc += abs(v[curr]);
    else dec += abs(v[curr]);
    dp[curr][0] += inc;
    dp[curr][1] += dec;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        adj.clear();
        adj.resize(n + 1);
        v.clear();
        v.resize(n + 1);
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1;i<=n;i++) {
            cin >> v[i];
        }
        dp.clear();
        dp.resize(n + 1, vector<int>(2));
        dfs(1, -1);
        cout << dp[1][0] + dp[1][1] << endl;
    }
}