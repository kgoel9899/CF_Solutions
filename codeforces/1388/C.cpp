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

int n, m, ok;
vector<int> p, h, sub, good;
vector<vector<int>> adj;
// x = good, y = bad
// x - y = h[i];
// x + y = sub[i];
// x = (h[i] + sub[i]) / 2;
// y = (sub[i] - h[i]) / 2;
void dfs(int curr, int par) {
    int sum = 0;
    sub[curr] += p[curr];
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr);
        sub[curr] += sub[i];
        sum += good[i];
    }
    int x = h[curr] + sub[curr];
    int y = sub[curr] - h[curr];
    if(x % 2 || x / 2 < sum || x / 2 > sub[curr] || y % 2 || y < 0 || y / 2 > sub[curr]) {
        ok = 0;
        return;
    }
    x /= 2;
    good[curr] = x;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n >> m;
        p.clear();
        p.resize(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> p[i];
        }
        h.clear();
        h.resize(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> h[i];
        }
        adj.clear();
        adj.resize(n + 1);
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        sub.clear();
        sub.resize(n + 1);
        good.clear();
        good.resize(n + 1);
        ok = 1;
        dfs(1, -1);
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}