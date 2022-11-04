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

void build(int l, int r, int node, vector<int>& v, vector<int>& tree) {
    if(l == r) {
        tree[node] = v[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * node, v, tree);
    build(mid + 1, r, 2 * node + 1, v, tree);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
int query(int l, int r, int node, int st, int end, vector<int>& tree) {
    if(st > end) return 0;
    if(l > end || r < st) return 0;
    if(st <= l && r <= end) return tree[node];
    int mid = (l + r) / 2;
    return max(query(l, mid, 2 * node, st, end, tree), query(mid + 1, r, 2 * node + 1, st, end, tree));
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> v(m);
        for(int i=0;i<m;i++) {
            cin >> v[i];
        }
        vector<int> tree(4 * m);
        build(0, m - 1, 1, v, tree);
        int q;
        cin >> q;
        while(q--) {
            int a, b, c, d, k;
            cin >> a >> b >> c >> d >> k;
            b--;
            d--;
            dbg(a, b, c, d, k);
            int left = min(b, d);
            int right = max(b, d);
            int mx = query(0, m - 1, 1, left + 1, right - 1, tree);
            dbg(mx);
            if(mx == n || (d - b) % k != 0) {
                cout << "NO" << endl;
                continue;
            }
            a += ((n - a) / k) * k;
            dbg(a);
            if(a <= mx) {
                cout << "NO" << endl;
                continue;
            }
            if((a - c) % k == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}