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

const int LOG = 10;
int dfs(int curr, int par, int d, vector<int>& node_leaves, vector<int>& dist, vector<vector<int>>& up, vector<vector<int>>& adj) {
    int ans = 0, ok = 0;
    up[curr][0] = par;
    dist[curr] = d;
    for(auto& i : adj[curr]) {
        if(i == par) continue;
        ans += dfs(i, curr, d + 1, node_leaves, dist, up, adj);
        ok = 1;
        node_leaves[curr] += node_leaves[i];
    }
    if(!ok) {
        ans++;
        node_leaves[curr] = 1;
    }
    return ans;
}
void fillUpTable(int n, vector<vector<int>>& up) {
    for(int j=1;j<LOG;j++) {
        for(int i=1;i<=n;i++) {
            int intermediate = up[i][j - 1];
            if(intermediate != -1) up[i][j] = up[intermediate][j - 1];
        }
    }
}
int kthParent(int u, int k, vector<vector<int>>& up) {
    int node = u;
    for(int i=LOG-1;i>=0;i--) {
        if(((k >> i) & 1) == 1) node = up[node][i];
        if(node == -1) return node;
    }
    return node;
}
int getLCA(int a, int b, vector<int>& dist, vector<vector<int>>& up) {
    if(dist[a] > dist[b]) swap(a, b);
    b = kthParent(b, dist[b] - dist[a], up);
    if(a == b) return a;
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
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<vector<int>> up(n + 1, vector<int>(LOG, -1));
        vector<int> dist(n + 1), node_leaves(n + 1);
        int leaves = dfs(1, -1, 0, node_leaves, dist, up, adj);
        vector<int> order;
        for(int i=0;i<leaves;i++) {
            int a;
            cin >> a;
            order.push_back(a);
        }
        fillUpTable(n, up);
        vector<int> ans, vis(n + 1);
        int curr = 0, ok = 1, prev = 1;
        while(curr < leaves) {
            int lca = getLCA(prev, order[curr], dist, up);
            if(prev != 1) {
                int temp_node = prev;
                while(temp_node != lca) {
                    if(node_leaves[temp_node] >= 1) {
                        ok = 0;
                        break;
                    }
                    temp_node = up[temp_node][0];
                }
            }
            if(!ok) break;
            int other = order[curr];
            while(prev != lca) {
                ans.push_back(prev);
                prev = up[prev][0];
            }
            vector<int> temp;
            while(other != up[lca][0]) {
                temp.push_back(other);
                other = up[other][0];
            }
            reverse(all(temp));
            for(auto& j : temp) {
                ans.push_back(j);
            }
            other = order[curr];
            while(other != -1) {
                node_leaves[other]--;
                other = up[other][0];
            }
            prev = up[order[curr]][0];
            curr++;
        }
        if(!ok) {
            cout << -1 << endl;
            continue;
        }
        while(prev != -1) {
            ans.push_back(prev);
            prev = up[prev][0];
        }
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}