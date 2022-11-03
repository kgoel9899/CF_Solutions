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

void build(int l, int r, int node, vector<int>& v, vector<int>& tree, int xr) {
    if(l == r) {
        tree[node] = v[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * node, v, tree, xr ^ 1);
    build(mid + 1, r, 2 * node + 1, v, tree, xr ^ 1);
    if(xr) tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    else tree[node] = tree[2 * node] | tree[2 * node + 1];
}
void update(int l, int r, int node, int ind, int val, vector<int>& tree, int xr) {
    if(ind < l || ind > r) return;
    if(l == r) {
        tree[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, 2 * node, ind, val, tree, xr ^ 1);
    update(mid + 1, r, 2 * node + 1, ind, val, tree, xr ^ 1);
    if(xr) tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    else tree[node] = tree[2 * node] | tree[2 * node + 1];
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        int tot = (1ll << n);
        vector<int> v(tot);
        for(int i=0;i<tot;i++) {
            cin >> v[i];
        }
        dbg(v);
        vector<int> tree(2 * tot);
        build(0, tot - 1, 1, v, tree, n % 2 == 0);
        dbg(tree);
        while(m--) {
            int ind, val;
            cin >> ind >> val;
            ind--;
            update(0, tot - 1, 1, ind, val, tree, n % 2 == 0);
            cout << tree[1] << endl;
        }
    }
}