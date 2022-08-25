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

int n, x, y;
vector<vector<int>> adj;
vector<int> sub;
int child;
bool dfs(int curr, int par) {
    sub[curr] = 1;
    int ok = 0;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        ok |= dfs(i, curr);
        sub[curr] += sub[i];
    }
    if(curr == y) ok = 1;
    if(par == x && ok) child = curr;
    return ok;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> x >> y;
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
        child = -1;
        dfs(x, -1);
        dbg(sub);
        dbg(child);
        cout << n * (n - 1) - sub[y] * (sub[x] - sub[child]) << endl;
    }
}