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

void build(int l, int r, int node, vector<int>& tree, vector<int>& v) {
    if(l == r) {
        tree[node] = v[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * node, tree, v);
    build(mid + 1, r, 2 * node + 1, tree, v);
    tree[node] = (tree[2 * node] & tree[2 * node + 1]);
}
int query(int l, int r, int node, int ql, int qr, vector<int>& tree) {
    if(l > qr || r < ql) return -1;
    if(l >= ql && r <= qr) return tree[node];
    int mid = (l + r) / 2;
    int left = query(l, mid, 2 * node, ql, qr, tree);
    int right = query(mid + 1, r, 2 * node + 1, ql, qr, tree);
    return (left & right);
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m, vector<int>(3));
        for(int i=0;i<m;i++) {
            cin >> v[i][0] >> v[i][1] >> v[i][2];
            v[i][0]--;
            v[i][1]--;
        }
        vector<int> ans(n), tree(4 * n);
        for(int i=0;i<32;i++) {
            vector<int> pref(n + 1);
            for(int j=0;j<m;j++) {
                if(((v[j][2] >> i) & 1) == 1) {
                    pref[v[j][0]]++;
                    pref[v[j][1] + 1]--;
                }
            }
            for(int j=1;j<=n;j++) {
                pref[j] += pref[j - 1];
            }
            for(int j=0;j<n;j++) {
                if(pref[j]) ans[j] |= (1ll << i);
            }
        }
        build(0, n - 1, 1, tree, ans);
        int ok = 1;
        for(int i=0;i<m;i++) {
            if(query(0, n - 1, 1, v[i][0], v[i][1], tree) != v[i][2]) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            cout << "YES" << endl;
            for(auto i : ans) {
                cout << i << " ";
            }
            cout << endl;
        } else cout << "NO" << endl;
    }
} 