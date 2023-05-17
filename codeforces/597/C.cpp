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

int query(int l, int r, int node, int st, int end, vector<int>& tree) {
    if(l > end || r < st) return 0;
    if(st <= l && r <= end) return tree[node];
    int mid = (l + r) / 2;
    return query(l, mid, 2 * node, st, end, tree) + query(mid + 1, r, 2 * node + 1, st, end, tree);
}
void update(int l, int r, int node, int ind, int val, vector<int>& tree) {
    if(ind < l || ind > r) return;
    if(l == r) {
        tree[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, 2 * node, ind, val, tree);
    update(mid + 1, r, 2 * node + 1, ind, val, tree);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<vector<int>> tree(k + 1, vector<int>(4 * n)), dp(n, vector<int>(k + 1));
        int ans = 0;
        for(int i=0;i<n;i++) {
            update(0, n - 1, 1, v[i], 1, tree[0]);
            dp[i][0] = 1;
            for(int j=1;j<=k;j++) {
                dp[i][j] = query(0, n - 1, 1, 0, v[i] - 1, tree[j - 1]);
                update(0, n - 1, 1, v[i], dp[i][j], tree[j]);
            }
            ans += dp[i][k];
        }
        cout << ans << endl;
    }
} 