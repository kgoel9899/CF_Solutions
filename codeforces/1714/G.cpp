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
vector<int> dist, asum, bsum, ans;
vector<vector<vector<int>>> adj;
void dfs(int curr, int p, int d) {
    dist[curr] = d;
    for(auto i : adj[curr]) {
        int to = i[0], a = i[1], b = i[2];
        if(to == p) continue;
        asum[to] = asum[curr] + a;
        bsum[to] = bsum[curr] + b;
        // dbg(to);
        dfs(to, curr, d + 1);
    }
}
void dfs2(int curr, int p, vector<int>& temp) {
    temp.push_back(curr);
    int beg = 0, end = (int)temp.size() - 1;
    int fin = -1;
    while(beg <= end) {
        int mid = (beg + end) / 2;
        if(bsum[temp[mid]] <= asum[curr]) {
            fin = temp[mid];
            beg = mid + 1;
        } else end = mid - 1;
    }
    // dbg(i[0], temp, fin);
    if(fin != -1) ans[curr] = dist[fin];
    for(auto i : adj[curr]) {
        if(i[0] == p) continue;
        dfs2(i[0], curr, temp);
    }
    temp.pop_back();
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n;
        adj.clear();
        adj.resize(n + 1);
        for(int i=2;i<=n;i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({i, b, c});
            adj[i].push_back({a, b, c});
        }
        dist.clear();
        dist.resize(n + 1);
        asum.clear();
        asum.resize(n + 1);
        bsum.clear();
        bsum.resize(n + 1);
        dfs(1, 0, 0);
        // dbg(dist);
        // dbg(asum);
        // dbg(bsum);
        ans.clear();
        ans.resize(n + 1);
        vector<int> temp;
        dfs2(1, 0, temp);
        for(int i=2;i<=n;i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}