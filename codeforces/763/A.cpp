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
vector<vector<int>> adj;
vector<pair<int, int>> v;
vector<int> col;
void dfs(int curr, int par) {
    for(auto i : adj[curr]) {
        if(i == par) continue;
        if(col[i] != col[curr]) v.push_back({i, curr});
        dfs(i, curr);
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
        col.clear();
        col.resize(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> col[i];
        }
        v.clear();
        dfs(1, -1);
        dbg(v);
        if(v.size() == 0) {
            cout << "YES" << endl;
            cout << 1 << endl;
            continue;
        }
        int ans = v[0].first, ok = 1;
        for(int i=1;i<v.size();i++) {
            if(v[i].first != ans && v[i].second != ans) ok = 0;
        }
        if(ok) {
            cout << "YES" << endl;
            cout << ans << endl;
            continue;
        }
        ok = 1;
        ans = v[0].second;
        for(int i=1;i<v.size();i++) {
            if(v[i].first != ans && v[i].second != ans) ok = 0;
        }
        if(ok) {
            cout << "YES" << endl;
            cout << ans << endl;
            continue;
        }
        cout << "NO" << endl;
    }
} 