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

int n, k, ct;
vector<int> sub;
vector<vector<int>> adj;
void dfs(int curr, int par, int mid) {
    sub[curr] = 1;
    for(auto i : adj[curr]) {
        if(i == par) continue;
        dfs(i, curr, mid);
        sub[curr] = max(sub[curr], 1 + sub[i]);
    }
    if(curr != 1) {
        if(sub[curr] == mid && par != 1) {
            // reroot this subtree
            ct++;
            sub[curr] = 0;
        }
    }
}
bool solve(int mid) {
    sub.clear();
    sub.resize(n + 1);
    ct = 0;
    dfs(1, 0, mid);
    return ct <= k;
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
            int x;
            cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
        int beg = 1, end = n - 1;
        int ans = end;
        while(beg <= end) {
            int mid = (beg + end) / 2;
            if(solve(mid)) {
                ans = mid;
                end = mid - 1;
            } else beg = mid + 1;
        }
        cout << ans << endl;
    }
}