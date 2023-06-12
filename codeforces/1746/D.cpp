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
vector<int> s;
vector<vector<int>> adj;
vector<map<int, int>> dp;
bool compare(pair<int, int>& a, pair<int, int>& b) {
    int x = a.second - a.first;
    int y = b.second - b.first;
    return x > y;
}
int dfs(int curr, int paths) {
    if(adj[curr].size() == 0) {
        dbg(curr, paths); return paths * s[curr];
    }
    dbg("###### ", curr, paths);
    if(dp[curr].find(paths) != dp[curr].end()) return dp[curr][paths];
    vector<pair<int, int>> v;
    int ct = adj[curr].size();
    for(auto& i : adj[curr]) {
        pair<int, int> here;
        dbg("1111111", i, curr);
        here.first = dfs(i, floor(paths * 1.0 / ct));
        dbg("2222222", i, curr);
        here.second = dfs(i, ceil(paths * 1.0  / ct));
        dbg(curr, paths, here);
        v.push_back(here);
    }
    sort(all(v), compare);
    int extra = paths % ct;
    int ans = 0;
    assert(ct == v.size());
    for(int i=0;i<ct;i++) {
        if(i < extra) ans += v[i].second;
        else ans += v[i].first;
    }
    dbg(ans, curr, paths);
    return dp[curr][paths] = ans + paths * s[curr];
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n >> k;
        adj.clear();
        adj.resize(n + 1);
        for(int i=2;i<=n;i++) {
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
        dbg(adj);
        s.clear();
        s.resize(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> s[i];
        }
        dp.clear();
        dp.resize(n + 1);
        cout << dfs(1, k) << endl;
    }
}