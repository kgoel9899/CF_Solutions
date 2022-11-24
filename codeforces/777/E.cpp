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
    return max(query(l, mid, 2 * node, st, end, tree), query(mid + 1, r, 2 * node + 1, st, end, tree));
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
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
bool compare(vector<int>& a, vector<int>& b) {
    if(a[1] != b[1]) return a[1] > b[1];
    return a[0] > b[0];
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(3));
        for(int i=0;i<n;i++) {
            cin >> v[i][0] >> v[i][1] >> v[i][2];
        }
        sort(all(v), compare);
        dbg(v);
        set<int> s;
        for(auto& i : v) {
            s.insert(i[0]);
            s.insert(i[1]);
        }
        map<int, int> m;
        int rank = 0;
        for(auto& i : s) {
            m[i] = rank++;
        }
        for(int i=0;i<n;i++) {
            v[i][0] = m[v[i][0]];
            v[i][1] = m[v[i][1]];
        }
        dbg(v);
        vector<int> tree(4 * rank);
        int ans = 0;
        for(int i=0;i<n;i++) {
            int mx = query(0, rank - 1, 1, 0, v[i][1] - 1, tree);
            ans = max(ans, v[i][2] + mx);
            update(0, rank - 1, 1, v[i][0], v[i][2] + mx, tree);
        }
        cout << ans << endl;
    }
}