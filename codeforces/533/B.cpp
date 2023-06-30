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
vector<int> v;
vector<vector<int>> adj, dp;
void dfs(int curr, int par) {
    dp[curr][1] = -INF;
    for(auto& i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr);
        int ev = dp[curr][0], odd = dp[curr][1];
        dp[curr][0] = max(ev + dp[i][0], odd + dp[i][1]);
        dp[curr][1] = max(ev + dp[i][1], odd + dp[i][0]);
    }
    dp[curr][1] = max(dp[curr][1], v[curr] + dp[curr][0]);
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        v.clear();
        v.resize(n + 1);
        adj.clear();
        adj.resize(n + 1);
        for(int i=1;i<=n;i++) {
            int p;
            cin >> p;
            if(p != -1) adj[p].push_back(i);
            cin >> v[i];
        }
        dp.clear();
        dp.resize(n + 1, vector<int>(2));
        dfs(1, 0);
        dbg(dp);
        cout << max(dp[1][0], dp[1][1]) << endl;
    }
}