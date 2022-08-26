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
vector<vector<pair<int, int>>> adj;
unordered_map<int, unordered_set<int>> m;
vector<int> ans;
bool dfs(int curr, int par) {
    bool ok = false;
    for(auto i : adj[curr]) {
        if(i.first == par) continue;
        ok |= dfs(i.first, curr);
    }
    if(ok) return ok;
    if(m[curr].find(par) != m[curr].end()) {
        ans.push_back(curr);
        return true;
    } else return false;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        adj.clear();
        adj.resize(n + 1);
        m.clear();
        for(int i=0;i<n-1;i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
            if(c == 2) {
                m[a].insert(b);
                m[b].insert(a);
            }
        }
        ans.clear();
        dfs(1, -1);
        cout << ans.size() << endl;
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}