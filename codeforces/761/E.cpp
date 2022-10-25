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
vector<vector<int>> adj, ans;
void dfs(int curr, int par, int dir, int x, int y, int pw) {
    ans[curr] = {x, y};
    const int two = (1ll << pw);
    set<int> vis;
    vis.insert(-dir);
    for(auto i : adj[curr]) {
        if(i == par) continue;
        if(vis.find(-2) == vis.end()) {
            dfs(i, curr, -2, x, y - two, pw - 1);
            vis.insert(-2);
        } else if(vis.find(-1) == vis.end()) {
            dfs(i, curr, -1, x + two, y, pw - 1);
            vis.insert(-1);
        } else if(vis.find(1) == vis.end()) {
            dfs(i, curr, 1, x - two, y, pw - 1);
            vis.insert(1);
        } else if(vis.find(2) == vis.end()) {
            dfs(i, curr, 2, x, y + two, pw - 1);
            vis.insert(2);
        } else assert(0);
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
        int ok = 1;
        for(int i=1;i<=n;i++) {
            if(adj[i].size() > 4) ok = 0;
        }
        if(!ok) {
            cout << "NO" << endl;
            continue;
        }
        ans.clear();
        ans.resize(n + 1);
        // L = 1, R = -1, U = 2, D = -2
        dfs(1, 0, -5, 0, 0, 40);
        cout << "YES" << endl;
        for(int i=1;i<=n;i++) {
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
    }
}