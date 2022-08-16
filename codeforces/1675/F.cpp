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

int n, k;
int x, y;
unordered_set<int> s;
vector<vector<int>> adj;
vector<int> path, vis, sub;
bool dfs(int curr, int par) {
    if(curr == y) return true;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        path.push_back(i);
        if(!dfs(i, curr)) path.pop_back();
        else return true;
    }
    return false;
}
void dfs1(int curr, int ind) {
    vis[curr] = 1;
    for(auto i : adj[curr]) {
        if(i == path[ind + 1] || vis[i]) continue;
        dfs1(i, ind);
        if(s.find(i) != s.end() || sub[i]) sub[curr] += sub[i] + 2;
    }
}
void dfs2(int curr) {
    vis[curr] = 1;
    for(auto i : adj[curr]) {
        if(vis[i]) continue;
        dfs2(i);
        if(s.find(i) != s.end() || sub[i]) sub[curr] += sub[i] + 2;
    }
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n >> k;
        cin >> x >> y;
        s.clear();
        for(int i=0;i<k;i++) {
            int num;
            cin >> num;
            s.insert(num);
        }
        adj.clear();
        adj.resize(n + 1);
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        path.clear();
        path.push_back(x);
        dfs(x, -1);
        dbg(path);
        vis.clear();
        vis.resize(n + 1);
        sub.clear();
        sub.resize(n + 1);
        int ans = 0;
        for(int i=0;i<(int)path.size()-1;i++) {
            dfs1(path[i], i);
            ans++;
            ans += sub[path[i]];
        }
        dbg(ans);
        dfs2(y);
        ans += sub[y];
        cout << ans << endl;
    }
}