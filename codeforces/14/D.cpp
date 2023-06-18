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

int n, node, diam;
vector<vector<int>> adj;
void dfs(int curr, int par, int dist) {
    if(dist > diam) {
        node = curr;
        diam = dist;
    }
    for(auto& i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr, dist + 1);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        vector<vector<int>> edges;
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            edges.push_back({a, b});
        }
        int ans = 0;
        for(int i=0;i<n-1;i++) {
            adj.clear();
            adj.resize(n + 1);
            for(int j=0;j<n-1;j++) {
                if(i == j) continue;
                int a = edges[j][0], b = edges[j][1];
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
            int x = edges[i][0];
            // diameter in tree x and y
            node = x, diam = 0;
            dfs(x, -1, 0);
            dfs(node, -1, 0);
            int d1 = diam;
            int y = edges[i][1];
            node = y, diam = 0;
            dfs(y, -1, 0);
            dfs(node, -1, 0);
            int d2 = diam;
            ans = max(ans, d1 * d2);
        }
        cout << ans << endl;
    }
}