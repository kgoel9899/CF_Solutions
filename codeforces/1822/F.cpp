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

int n, k, c;
vector<int> dist, out;
vector<vector<int>> adj;
vector<vector<pair<int, int>>> ht; // for every node store max 2 heights and corresponding nodes
void dfs(int curr, int par) {
    for(auto& i : adj[curr]) {
        if(i == par) continue;
        dist[i] = 1 + dist[curr];
        dfs(i, curr);
        if(1 + ht[i][0].first >= ht[curr][0].first) {
            ht[curr][1] = ht[curr][0];
            ht[curr][0] = {1 + ht[i][0].first, i};
        } else if(1 + ht[i][0].first > ht[curr][1].first) ht[curr][1] = {1 + ht[i][0].first, i};
    }
}
// void dfs2(int curr, int par) {
//     for(auto& i : adj[curr]) {
//         if(i == par) continue;
//         int mx_ht = ht[i][0].first, mx_node = ht[i][0].second;
//         if(ht[curr][0].second == i) {
//             if(1 + ht[curr][1].first > mx_ht) {
//                 mx_ht = 1 + ht[curr][1].first;
//                 mx_node = curr;
//             }
//         } else {
//             if(1 + ht[curr][0].first > mx_ht) {
//                 mx_ht = 1 + ht[curr][0].first;
//                 mx_node = curr;
//             }
//         }
//         dbg(i, curr, mx_ht, mx_node);
//         ans = max(ans, mx_ht * k - dist[i] * c);
//         if(mx_ht > ht[i][0].first || (mx_ht == ht[i][0].first && mx_node != ht[i][0].second)) {
//             ht[i][1] = ht[i][0];
//             dbg("here", i, curr);
//             ht[i][0] = {mx_ht, mx_node};
//         } else if(mx_ht > ht[i][1].first) ht[i][1] = {mx_ht, mx_node};
//         dbg(ht);
//         dfs2(i, curr);
//     }
// }
void dfs2(int curr, int par) {
    for(auto& i : adj[curr]) {
        if(i == par) continue;
        out[i] = out[curr] + 1;
        dbg(i, curr, out[i], ht[curr]);
        if(ht[curr][0].second == i) out[i] = max(out[i], 1 + ht[curr][1].first);
        else out[i] = max(out[i], 1 + ht[curr][0].first);
        dbg(i, curr, out[i]);
        dfs2(i, curr);
    }
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n >> k >> c;
        adj.clear();
        adj.resize(n + 1);
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dist.clear();
        dist.resize(n + 1);
        ht.clear();
        ht.resize(n + 1, vector<pair<int, int>>(2));
        out.clear();
        out.resize(n + 1);
        dfs(1, 0);
        dbg(dist);
        dbg(ht);
        dfs2(1, 0);
        dbg(out);
        int ans = ht[1][0].first * k;
        for(int i=2;i<=n;i++) {
            ans = max(ans, max(ht[i][0].first, out[i]) * k - dist[i] * c);
        }
        cout << ans << endl;
    }
}