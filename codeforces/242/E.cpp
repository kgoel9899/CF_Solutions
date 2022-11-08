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

void propagate(int l, int r, int node, vector<int>& lazy) {
    if(l != r) {
        lazy[2 * node] ^= lazy[node];
        lazy[2 * node + 1] ^= lazy[node];
    }
    lazy[node] = 0;
}
void build(int l, int r, int node, vector<int>& v, vector<vector<int>>& tree) {
    if(l == r) {
        for(int i=0;i<25;i++) {
            if(((v[l] >> i) & 1) == 1) tree[node][i]++;
        }
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * node, v, tree);
    build(mid + 1, r, 2 * node + 1, v, tree);
    for(int i=0;i<25;i++) {
        tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
    }
}
void update(int l, int r, int node, int ql, int qr, int val, vector<vector<int>>& tree, vector<int>& lazy) {
    if(lazy[node] != 0) {
        for(int i=0;i<25;i++) {
            if(((lazy[node] >> i) & 1) == 1) tree[node][i] = (r - l + 1) - tree[node][i];
        }
        propagate(l, r, node, lazy);
    }
    if(l >= ql && r <= qr) {
        for(int i=0;i<25;i++) {
            if(((val >> i) & 1) == 1) tree[node][i] = (r - l + 1) - tree[node][i];
        }
        lazy[node] ^= val;
        propagate(l, r, node, lazy);
        return;
    }
    if(l > qr || r < ql) return;
    int mid = (l + r) / 2;
    update(l, mid, 2 * node, ql, qr, val, tree, lazy);
    update(mid + 1, r, 2 * node + 1, ql, qr, val, tree, lazy);
    for(int i=0;i<25;i++) {
        tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
    }
}
int query(int l, int r, int node, int ql, int qr, vector<vector<int>>& tree, vector<int>& lazy) {
    if(lazy[node] != 0) {
        for(int i=0;i<25;i++) {
            if(((lazy[node] >> i) & 1) == 1) tree[node][i] = (r - l + 1) - tree[node][i];
        }
        propagate(l, r, node, lazy);
    }
    if(l >= ql && r <= qr) {
        int ans = 0;
        for(int i=0;i<25;i++) {
            ans += (1ll << i) * tree[node][i];
        }
        return ans;
    }
    if(l > qr || r < ql) return 0;
    int mid = (l + r) / 2;
    int left = query(l, mid, 2 * node, ql, qr, tree, lazy);
    int right = query(mid + 1, r, 2 * node + 1, ql, qr, tree, lazy);
    return left + right;
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<vector<int>> tree(4 * n, vector<int>(25));
        vector<int> lazy(4 * n);
        int m;
        cin >> m;
        build(0, n - 1, 1, v, tree);
        while(m--) {
            int t, l, r;
            cin >> t >> l >> r;
            l--;
            r--;
            if(t == 2) {
                int x;
                cin >> x;
                update(0, n - 1, 1, l, r, x, tree, lazy);
            } else cout << query(0, n - 1, 1, l, r, tree, lazy) << endl;
        }
    }
}