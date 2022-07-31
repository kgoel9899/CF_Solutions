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

int n, m;
string s;
vector<vector<int>> adj, dp;
vector<int> indeg, vis;
bool cycle(int curr) {
    if(vis[curr] == 1) return true;
    if(vis[curr] == 2) return false;
    vis[curr] = 1; // in
    for(auto i : adj[curr]) {
        if(vis[i] == 2) continue;
        if(vis[i] == 1 || cycle(i)) return true;
    }
    vis[curr] = 2; // out
    return false;
}
void dfs(int curr) {
    vis[curr] = 1;
    vector<int> temp(26);
    for(auto i : adj[curr]) {
        if(!vis[i]) dfs(i);
        for(int j=0;j<26;j++) {
            temp[j] = max(temp[j], dp[i][j]);
        }
    }
    dp[curr] = temp;
    dp[curr][s[curr] - 'a']++;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> m;
        cin >> s;
        s = '#' + s;
        adj.clear();
        adj.resize(n + 1);
        indeg.clear();
        indeg.resize(n + 1);
        for(int i=0;i<m;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            indeg[b]++;
        }
        vis.clear();
        vis.resize(n + 1);
        int ok = 1;
        for(int i=1;i<=n;i++) {
            if(cycle(i)) {
                ok = 0;
                break;
            }
        }
        if(!ok) {
            cout << -1 << endl;
            continue;
        }
        dp.clear();
        dp.resize(n + 1, vector<int>(26));
        fill(all(vis), 0);
        int ans = 0;
        for(int i=1;i<=n;i++) {
            if(indeg[i] == 0) {
                // dbg(i);
                dfs(i);
                for(int j=0;j<26;j++) {
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        // for(int i=1;i<=n;i++) {
        //     cout << "Node " << i << endl;
        //     for(int j=0;j<26;j++) {
        //         if(dp[i][j]) cout << char('a' + j) << ": " << dp[i][j] << endl;
        //     }
        //     cout << endl;
        // }
        cout << ans << endl;
    }
}
/*
1
1 10 9 - xxq
1 2 10 9 - xzxq
1 2 8 - xzz
1 2 6 5 - xzzy
*/