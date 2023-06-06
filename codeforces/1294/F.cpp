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

const int LOG = 22;
int n;
vector<int> parent;
vector<vector<int>> adj;
void dfs(int curr, int par, vector<int>& dist) {
    parent[curr] = par;
    for(auto& i : adj[curr]) {
        if(i == par) continue;
        dist[i] = 1 + dist[curr];
        dfs(i, curr, dist);
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
        parent.clear();
        parent.resize(n + 1);
        vector<int> dist1(n + 1);
        dfs(1, 0, dist1);
        int a, d1 = 0;
        for(int i=1;i<=n;i++) {
            if(dist1[i] > d1) {
                d1 = dist1[i];
                a = i;
            }
        }
        dbg(a);
        parent.clear();
        parent.resize(n + 1);
        vector<int> dist2(n + 1);
        dfs(a, 0, dist2);
        int b, d2 = 0;
        for(int i=1;i<=n;i++) {
            if(dist2[i] > d2) {
                d2 = dist2[i];
                b = i;
            }
        }
        dbg(b);
        queue<int> q;
        dbg(parent);
        int temp = b;
        vector<int> vis(n + 1, -1);
        while(temp != a) {
            q.push(temp);
            vis[temp] = 0;
            temp = parent[temp];
            dbg(temp);
        }
        q.push(a);
        vis[a] = 0;
        int diameter = q.size();
        if(q.size() == n) {
            cout << n - 1 << endl;
            q.pop();
            cout << a << " " << b << " " << q.front() << endl;
            continue;
        }
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            for(auto& i : adj[f]) {
                if(vis[i] == -1) {
                    vis[i] = vis[f] + 1;
                    q.push(i);
                }
            }
        }
        int best = 0, node = -1;
        for(int i=1;i<=n;i++) {
            if(vis[i] > best) {
                best = vis[i];
                node = i;
            }
        }
        cout << diameter + vis[node] - 1 << endl;
        cout << a << " " << b << " " << node << endl;
    }
}