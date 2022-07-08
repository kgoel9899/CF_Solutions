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
vector<vector<int>> adj, dp, s;
vector<int> ans;
void dfs(int curr, int par) {
    dp[curr][1] = 1;
    dp[curr][0] = 0;
    s[curr][1] = adj[curr].size();
    s[curr][0] = 1;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr);
        dp[curr][1] += dp[i][0];
        s[curr][1] += s[i][0];
        dp[curr][0] += max(dp[i][0], dp[i][1]);
        if(dp[i][0] > dp[i][1]) s[curr][0] += s[i][0];
        else if(dp[i][0] < dp[i][1]) s[curr][0] += s[i][1];
        else s[curr][0] += min(s[i][0], s[i][1]);
    }
}
void dfs2(int curr, int par, int take) {
    if(take) ans[curr] = adj[curr].size();
    else ans[curr] = 1;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        if(take) {
            dfs2(i, curr, 0);
            continue;
        }
        if(dp[i][0] > dp[i][1]) dfs2(i, curr, 0);
        else if(dp[i][0] < dp[i][1]) dfs2(i, curr, 1);
        else {
            if(s[i][0] > s[i][1]) dfs2(i, curr, 1);
            else dfs2(i, curr, 0);
        }
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
        if(n == 2) {
            cout << "2 2" << endl;
            cout << "1 1" << endl;
            continue;
        }
        dp.clear();
        dp.resize(n + 1, vector<int>(2));
        s.clear();
        s.resize(n + 1, vector<int>(2));
        dfs(1, 0);
        dbg(dp);
        dbg(s);
        ans.clear();
        ans.resize(n + 1);
        if(dp[1][0] > dp[1][1]) dfs2(1, 0, 0);
        else if(dp[1][0] < dp[1][1]) dfs2(1, 0, 1);
        else {
            // both dp values are equal i.e. both have same max number of good vertices,
            // so construct on the basis of min sum
            if(s[1][0] > s[1][1]) dfs2(1, 0, 1);
            else dfs2(1, 0, 0);
        }
        cout << max(dp[1][0], dp[1][1]) << " ";
        if(dp[1][0] > dp[1][1]) cout << s[1][0] << endl;
        else if(dp[1][0] < dp[1][1]) cout << s[1][1] << endl;
        else cout << min(s[1][0], s[1][1]) << endl;
        for(int i=1;i<=n;i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}