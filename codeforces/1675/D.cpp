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

int n;
vector<int> p, vis;
vector<vector<int>> adj;
void dfs(int curr, vector<int>& temp) {
    temp.push_back(curr);
    vis[curr] = 1;
    if(adj[curr].size() == 0) return;
    dfs(adj[curr][0], temp);
}
int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        cin >> n;
        p.clear();
        p.resize(n + 1);
        adj.clear();
        adj.resize(n + 1);
        vis.clear();
        vis.resize(n + 1);
        int root;
        for(int i=1;i<=n;i++) {
            cin >> p[i];
            if(p[i] == i) root = i;
            else {
                adj[p[i]].push_back(i);
                // adj[i].push_back(p[i]);
            }
        }
        // dbg(adj);
        queue<int> q;
        q.push(root);
        // vis[root] = 1;
        vector<vector<int>> ans;
        while(!q.empty()) {
            int f = q.front();
            // dbg(f);
            q.pop();
            if(vis[f] == 0) {
                vector<int> temp;
                dfs(f, temp);
                ans.push_back(temp);
            }
            // vis[f] = 1;
            for(int i=0;i<adj[f].size();i++) {
                // assert(vis[adj[f][i]] == 0);
                // vis[adj[f][i]] = 1;
                // dbg(adj[f][i]);
                q.push(adj[f][i]);
            }
        }
        cout << ans.size() << endl;
        for(auto i : ans) {
            cout << i.size() << endl;
            for(auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}