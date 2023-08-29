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

struct Node {
    int mn, g;
};
Node merge(Node& op1, Node& op2) {
    Node ans = {min(op1.mn, op2.mn), __gcd(op1.g, op2.g)};
    return ans;
}
void build(int l, int r, int node, vector<int>& v, vector<Node>& tree) {
    if(l == r) {
        tree[node] = {v[l], v[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * node, v, tree);
    build(mid + 1, r, 2 * node + 1, v, tree);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}
Node query(int l, int r, int node, int st, int end, vector<Node>& tree) {
    if(l > end || r < st) return {INF, 0};
    if(l >= st && r <= end) return tree[node];
    int mid = (l + r) / 2;
    Node op1 = query(l, mid, 2 * node, st, end, tree);
    Node op2 = query(mid + 1, r, 2 * node + 1, st, end, tree);
    return merge(op1, op2);
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
        vector<Node> tree(4 * n);
        build(0, n - 1, 1, v, tree);
        map<int, vector<int>> m;
        for(int i=0;i<n;i++) {
            m[v[i]].push_back(i);
        }
        int q;
        cin >> q;
        while(q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            Node ans = query(0, n - 1, 1, l, r, tree);
            int tot = r - l + 1;
            if(ans.mn != ans.g) cout << tot << endl;
            else {
                int ind1 = upper_bound(all(m[ans.g]), r) - m[ans.g].begin();
                int ind2 = lower_bound(all(m[ans.g]), l) - m[ans.g].begin();
                cout << tot - (ind1 - ind2) << endl;
            }
        }
    }
}