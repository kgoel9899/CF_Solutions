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
vector<int> nums, sub;
vector<vector<pair<int, int>>> adj;
void dfs(int curr, int par) {
    sub[curr] = 1;
    for(auto& i : adj[curr]) {
        if(i.first == par) continue;
        dfs(i.first, curr);
        sub[curr] += sub[i.first];
    }
}
void dfs2(int curr, int par, int here) {
    if(curr != 1) {
        if(here > nums[curr]) {
            ans += sub[curr];
            dbg(here, curr, ans);
            return;
        }
    }
    for(auto& i : adj[curr]) {
        if(i.first == par) continue;
        dfs2(i.first, curr, max(0ll, here + i.second));
    }
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        nums.clear();
        nums.resize(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> nums[i];
        }
        adj.clear();
        adj.resize(n + 1);
        for(int i=2;i<=n;i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back({i, b});
            adj[i].push_back({a, b});
        }
        dbg(adj);
        sub.clear();
        sub.resize(n + 1);
        dfs(1, 0);
        dbg(sub);
        ans = 0;
        dfs2(1, 0, 0);
        cout << ans << endl;
    }
}