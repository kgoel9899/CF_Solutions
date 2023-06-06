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
vector<vector<int>> adj, up;
void dfs(int curr, int par, vector<int>& dist) {
    parent[curr] = par;
    for(auto& i : adj[curr]) {
        if(i == par) continue;
        dist[i] = 1 + dist[curr];
        dfs(i, curr, dist);
    }
}
void fill0thParent(int curr, int par) {
    up[curr][0] = par;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        fill0thParent(i, curr);
    }
}
void fillUpTable() {
    for(int j=1;j<LOG;j++) {
        for(int i=1;i<=n;i++) {
            int intermediate = up[i][j - 1];
            if(intermediate != -1) up[i][j] = up[intermediate][j - 1];
        }
    }
}
vector<int> dist;
void calcDistFromRoot(int curr, int par, int lvl) {
    dist[curr] = lvl;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        calcDistFromRoot(i, curr, lvl + 1);
    }
}
int kthParent(int node, int k) {
    for(int i=LOG-1;i>=0;i--) {
        if((k >> i) & 1) node = up[node][i];
    }
    return node;
}
int getLCA(int a, int b) {
    if(dist[a] > dist[b]) swap(a, b); // make sure b is always deeper
    b = kthParent(b, dist[b] - dist[a]);
    // now a and b are at same level
    if(a == b) return a; // edge case
    for(int i=LOG-1;i>=0;i--) {
        int par1 = up[a][i];
        int par2 = up[b][i];
        if(par1 != par2 && par1 != -1 && par2 != -1) {
            a = par1;
            b = par2;
        }
    }
    return up[a][0];
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        adj.clear();
        adj.resize(n + 1);
        up.clear();
        up.resize(n + 1, vector<int>(LOG, -1));
        dist.clear();
        dist.resize(n + 1);
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        fill0thParent(1, -1);
        fillUpTable();
        calcDistFromRoot(1, -1, 0);
        int a, d1 = 0;
        for(int i=1;i<=n;i++) {
            if(dist[i] > d1) {
                d1 = dist[i];
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