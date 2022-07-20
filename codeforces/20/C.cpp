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
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n + 1);
        for(int i=0;i<m;i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INF), par(n + 1, -1);
        par[1] = 0;
        dist[1] = 0;
        pq.push({0, 1});
        while(!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            int v = f.second;
            int d_v = f.first;
            if(d_v != dist[v]) continue;
            for(auto i : adj[v]) {
                int to = i.first;
                int len = i.second;
                if(d_v + len < dist[to]) {
                    dist[to] = d_v + len;
                    pq.push({dist[to], to});
                    par[to] = v;
                }
            }
        }
        dbg(dist);
        dbg(par);
        if(dist[n] == INF) {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;
        int curr = n;
        while(curr != 0) {
            ans.push_back(curr);
            curr = par[curr];
        }
        reverse(all(ans));
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}