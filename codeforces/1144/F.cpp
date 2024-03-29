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
vector<vector<int>> adj;
vector<int> vis;
bool bipartite(int curr, int col) {
    vis[curr] = col;
    bool ans = true;
    for(auto i : adj[curr]) {
        if(vis[i] == -1) ans &= bipartite(i, 1 - col);
        else {
            if(vis[i] == col) return false;
        }
    }
    return ans;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> m;
        adj.clear();
        adj.resize(n + 1);
        vector<vector<int>> inp;
        for(int i=0;i<m;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            inp.push_back({a, b});
        }
        vis.clear();
        vis.resize(n + 1, -1);
        dbg(adj);
        bool ans = true;
        for(int i=0;i<n;i++) {
            if(vis[i] == -1) ans &= bipartite(i, 0);
        }
        if(ans) {
            cout << "YES" << endl;
            for(auto& i : inp) {
                int a = i[0], b = i[1];
                if(vis[a] == 0 && vis[b] == 1) cout << 1;
                else cout << 0;
            }
        } else cout << "NO" << endl;
    }
}