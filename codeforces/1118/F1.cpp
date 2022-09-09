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

int n, tot_red, tot_blue, ans;
vector<int> col, blue, red;
vector<vector<int>> adj;
void dfs(int curr, int par) {
    if(col[curr] == 1) red[curr]++;
    else if(col[curr] == 2) blue[curr]++;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr);
        red[curr] += red[i];
        blue[curr] += blue[i];
    }
}
void dfs2(int curr, int par) {
    for(auto i : adj[curr]) {
        if(i == par) continue;
        int r1 = tot_red - red[i];
        int b1 = tot_blue - blue[i];
        if((red[i] == 0 && b1 == 0) || (blue[i] == 0 && r1 == 0)) {
            dbg(curr, i);
            ans++;
        }
        dfs2(i, curr);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        col.clear();
        col.resize(n + 1);
        tot_red = 0;
        tot_blue = 0;
        for(int i=1;i<=n;i++) {
            cin >> col[i];
            if(col[i] == 1) tot_red++;
            else if(col[i] == 2) tot_blue++;
        }
        adj.clear();
        adj.resize(n + 1);
        for(int i=0;i<n-1;i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        blue.clear();
        blue.resize(n + 1);
        red.clear();
        red.resize(n + 1);
        dfs(1, -1);
        dbg(tot_red);
        dbg(tot_blue);
        dbg(red);
        dbg(blue);
        ans = 0;
        dfs2(1, -1);
        cout << ans << endl;
    }
}