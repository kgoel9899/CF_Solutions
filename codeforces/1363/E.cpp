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

// editorial
int n, ans;
vector<vector<int>> v, adj;
vector<int> dp1, dp2; // dp1[i] / dp2[i] = how many 1,0 / 0,1 type nodes are there in the subtree of i
void dfs(int curr, int par) {
    for(auto i : adj[curr]) {
        if(i == par) continue;
        v[i][0] = min(v[i][0], v[curr][0]);
        dfs(i, curr);
    }
}
void dfs2(int curr, int par) {
    if(v[curr][1] == 1 && v[curr][2] == 0) dp1[curr] = 1;
    if(v[curr][1] == 0 && v[curr][2] == 1) dp2[curr] = 1;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs2(i, curr);
        int rem = min(dp1[i], dp2[i]);
        ans += 2 * rem * v[i][0];
        dp1[curr] += dp1[i] - rem;
        dp2[curr] += dp2[i] - rem;
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        v.clear();
        v.resize(n + 1, vector<int>(3));
        adj.clear();
        adj.resize(n + 1);
        int x = 0, y = 0;
        for(int i=1;i<=n;i++) {
            cin >> v[i][0] >> v[i][1] >> v[i][2];
            if(v[i][1] == 1 && v[i][2] == 0) x++;
            else if(v[i][1] == 0 && v[i][2] == 1) y++;
        }
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(x != y) {
            cout << -1 << endl;
            continue;
        }
        dfs(1, 0);
        dbg(v);
        dbg(x, y);
        dp1.clear();
        dp1.resize(n + 1);
        dp2.clear();
        dp2.resize(n + 1);
        ans = 0;
        dfs2(1, 0);
        assert(dp1[1] == dp2[1]);
        ans += 2 * dp1[1] * v[1][0];
        cout << ans << endl;
    }
}