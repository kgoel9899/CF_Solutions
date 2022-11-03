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
    int mx, op, clo;
    Node() {
        mx = 0;
        op = 0;
        clo = 0;
    }
};
Node merge(Node& one, Node& two) {
    Node result;
    int temp = min(one.op, two.clo);
    result.mx = one.mx + two.mx + 2 * temp;
    result.op = one.op + two.op - temp;
    result.clo = one.clo + two.clo - temp;
    return result;
}
void build(int l, int r, int node, string& s, vector<Node>& tree) {
    if(l == r) {
        tree[node].mx = 0;
        tree[node].op = (s[l] == '(');
        tree[node].clo = (s[l] == ')');
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * node, s, tree);
    build(mid + 1, r, 2 * node + 1, s, tree);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}
Node query(int l, int r, int node, int st, int end, vector<Node>& tree) {
    if(l > end || r < st) return Node();
    if(st <= l && r <= end) return tree[node];
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
        string s;
        cin >> s;
        int n = s.size();
        vector<Node> tree(4 * n);
        build(0, n - 1, 1, s, tree);
        int m;
        cin >> m;
        while(m--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << query(0, n - 1, 1, l, r, tree).mx << endl;
        }
    }
}