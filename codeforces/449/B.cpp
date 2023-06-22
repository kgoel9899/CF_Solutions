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

int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<pair<int, int>>> adj(n + 1);
        for(int i=0;i<m;i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        dbg(adj);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i=0;i<k;i++) {
            int s, y;
            cin >> s >> y;
            pq.push({y, s, 1});
        }
        for(auto& i : adj[1]) {
            // pq.push({i.second, i.first, 0});
        }
        pq.push({0, 1, 0});
        vector<int> dist(n + 1, INF);
        dist[1] = 0;
        int used = 0;
        while(!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            // dbg(f[2], f[1], f[0], dist[f[1]]);
            if(f[2]) {
                if(f[0] < dist[f[1]]) {
                    used++;
                    dist[f[1]] = f[0];
                } else continue;
            }
            else if(dist[f[1]] != f[0]) continue;
            dbg(f[0], f[1], dist[f[1]]);
            for(auto& i : adj[f[1]]) {
                if(i.second + f[0] < dist[i.first]) {
                    dist[i.first] = i.second + f[0];
                    dbg(dist[i.first]);
                    pq.push({dist[i.first], i.first, 0});
                }
            }
        }
        dbg(dist);
        cout << k - used << endl;
    }
}