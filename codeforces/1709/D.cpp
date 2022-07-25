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

int n, m;
vector<int> v, tree;
void build(int st, int end, int node) {
    if(st == end) {
        tree[node] = v[st];
        return;
    }
    int mid = (st + end) / 2;
    build(st, mid, 2 * node);
    build(mid + 1, end, 2 * node + 1);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
int query(int l, int r, int st, int end, int node) {
    if(l > end || r < st) return 0;
    if(st >= l && end <= r) return tree[node];
    int mid = (st + end) / 2;
    return max(query(l, r, st, mid, 2 * node), query(l, r, mid + 1, end, 2 * node + 1));
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> m;
        v.clear();
        v.resize(m);
        for(int i=0;i<m;i++) {
            cin >> v[i];
        }
        tree.clear();
        tree.resize(4 * m);
        build(0, m - 1, 1);
        // dbg(tree);
        int q;
        cin >> q;
        while(q--) {
            int x1, y1, x2, y2, k;
            cin >> x1 >> y1 >> x2 >> y2 >> k;
            y1--;
            y2--;
            if(abs(y1 - y2) % k != 0 || abs(x1 - x2) % k != 0) {
                cout << "NO" << endl;
                continue;
            }
            int mx = query(min(y1, y2) + 1, max(y1, y2) - 1, 0, m - 1, 1);
            int mx_coord = x1 + ((n - x1) / k) * k;
            dbg(y1, y2, mx, mx_coord);
            if(mx >= mx_coord) {
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
        }
    }
}