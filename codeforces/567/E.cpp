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

void dijkstra(int node, vector<vector<pair<int, int>>>& adj, vector<pair<int, int>>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, node});
    dist[node] = {0, 1};
    while(!pq.empty()) {
        auto f = pq.top();
        pq.pop();
        int vert = f.second;
        int d = f.first;
        if(dist[vert].first != d) continue;
        for(auto& i : adj[vert]) {
            if(i.second + d < dist[i.first].first) {
                dist[i.first] = {i.second + d, dist[vert].second};
                pq.push({dist[i.first].first, i.first});
            } else if(i.second + d == dist[i.first].first) {
                dist[i.first].second += dist[vert].second;
                dist[i.first].second %= mod;
            }
        }
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        vector<vector<pair<int, int>>> adj(n + 1), adj_rev(n + 1);
        vector<vector<int>> roads;
        for(int i=0;i<m;i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj_rev[b].push_back({a, c});
            roads.push_back({a, b, c});
        }
        vector<pair<int, int>> dist1(n + 1, {INF, 0}), dist2(n + 1, {INF, 0});
        dijkstra(s, adj, dist1);
        dijkstra(t, adj_rev, dist2);
        dbg(dist1);
        dbg(dist2);
        int mn = dist1[t].first;
        for(auto& i : roads) {
            int a = i[0], b = i[1], c = i[2];
            int here_dist = dist1[a].first + c + dist2[b].first;
            int change = here_dist - mn + 1;
            if(here_dist == mn && (dist1[a].second * dist2[b].second) % mod == dist1[t].second) {
                cout << "YES" << endl;
                continue;
            }
            if(change >= c) cout << "NO" << endl;
            else cout << "CAN " << change << endl;
        }
    }
}