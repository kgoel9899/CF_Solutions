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

int n, ans;
vector<vector<int>> adj;
vector<int> l, r, sub;
void dfs(int curr, int par) {
    int s = 0;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr);
        s += sub[i];
    }
    if(s < l[curr]) {
        ans++;
        sub[curr] = r[curr];
    } else sub[curr] = min(s, r[curr]);
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n;
        ans = 0;
        adj.clear();
        adj.resize(n + 1);
        l.clear();
        l.resize(n + 1);
        r.clear();
        r.resize(n + 1);
        sub.clear();
        sub.resize(n + 1);
        for(int i=2;i<=n;i++) {
            int a;
            cin >> a;
            adj[i].push_back(a);
            adj[a].push_back(i);
        }
        for(int i=1;i<=n;i++) {
            cin >> l[i] >> r[i];
        }
        dfs(1, -1);
        cout << ans << endl;
    }
}