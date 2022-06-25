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

int n, m, q;
vector<vector<int>> adj, people;
vector<int> c, dist;
vector<vector<vector<int>>> up_people;
const int LOG = 18;
vector<vector<int>> up;
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
vector<int> merge(vector<int>& a, vector<int>& b) {
    vector<int> ans;
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()) {
        if(ans.size() == 10) return ans;
        if(a[i] <= b[j]) {
            ans.push_back(a[i]);
            i++;
        } else {
            ans.push_back(b[j]);
            j++;
        }
    }
    while(i < a.size()) {
        if(ans.size() == 10) return ans;
        ans.push_back(a[i]);
        i++;
    }
    while(j < b.size()) {
        if(ans.size() == 10) return ans;
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}
void calcDistFromRoot(int curr, int par, int d) {
    dist[curr] = d;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        calcDistFromRoot(i, curr, d + 1);
    }
}
int kthParent(int node, int k) {
    for(int i=LOG-1;i>=0;i--) {
        if(node == -1) break;
        if(((k >> i) & 1) == 1) node = up[node][i];
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
        cin >> n >> m >> q;
        adj.clear();
        adj.resize(n + 1);
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        c.clear();
        c.resize(m + 1);
        people.clear();
        people.resize(n + 1);
        for(int i=1;i<=m;i++) {
            cin >> c[i];
            people[c[i]].push_back(i);
        }
        up.clear();
        up.resize(n + 1, vector<int>(LOG, -1));
        fill0thParent(1, -1);
        fillUpTable();
        dist.clear();
        dist.resize(n + 1);
        calcDistFromRoot(1, -1, 0);
        up_people.clear();
        up_people.resize(n + 1, vector<vector<int>>(LOG));
        for(int i=1;i<=n;i++) {
            sort(all(people[i])); // person 'people[i][j]' lives in city 'i'
            vector<int> temp;
            up_people[i][0] = merge(people[i], temp);
        }
        for(int j=1;j<LOG;j++) {
            for(int i=1;i<=n;i++) {
                int intermediate = up[i][j - 1];
                if(i == 5) dbg(i, j, intermediate);
                if(intermediate != -1) up_people[i][j] = merge(up_people[i][j - 1], up_people[intermediate][j - 1]);
            }
        }
        dbg(up);
        dbg(people);
        dbg(up_people);
        while(q--) {
            int u, v, a;
            cin >> u >> v >> a;
            int lca = getLCA(u, v);
            vector<int> ans;
            int diff = dist[u] - dist[lca];
            for(int i=LOG-1;i>=0;i--) {
                if(diff && (diff & (1 << i)) && u != -1) {
                    ans = merge(ans, up_people[u][i]);
                    u = up[u][i];
                    diff -= (1 << i);
                }
            }
            diff = dist[v] - dist[lca];
            for(int i=LOG-1;i>=0;i--) {
                if(diff && (diff & (1 << i)) && v != -1) {
                    ans = merge(ans, up_people[v][i]);
                    v = up[v][i];
                    diff -= (1 << i);
                }
            }
            ans = merge(ans, people[lca]);
            int sz = min(a, (int)ans.size());
            cout << sz << " ";
            for(int i=0;i<sz;i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}