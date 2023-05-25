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
vector<int> rem;
vector<vector<int>> adj;
map<pair<int, int>, int> m;
int dfs(int curr, int par) {
    int tot = 1;
    for(auto& i : adj[curr]) {
        if(i == par) continue;
        int nodes = dfs(i, curr);
        if(nodes == -1) return -1;
        if(nodes == 3) {
            rem.push_back(m[{min(i, curr), max(i, curr)}]);
            continue;
        }
        if(nodes >= 4) return -1;
        tot += nodes;
    }
    return tot;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n;
        adj.clear();
        adj.resize(n + 1);
        m.clear();
        rem.clear();
        for(int i=0;i<n-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            m[{min(a, b), max(a, b)}] = i + 1;
        }
        if(dfs(1, 0) != 3) {
            cout << -1 << endl;
            continue;
        }
        cout << rem.size() << endl;
        for(auto& i : rem) {
            cout << i << " ";
        }
        cout << endl;
    }
}