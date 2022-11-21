// https://codeforces.com/contest/52/problem/C
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
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
}
void build(int l, int r, int node, vector<int>& tree, vector<int>& v) {
    if(l == r) {
        tree[node] = v[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * node, tree, v);
    build(mid + 1, r, 2 * node + 1, tree, v);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
void update(int l, int r, int node, int ql, int qr, int val, vector<int>& tree, vector<int>& lazy) {
    if(lazy[node] != 0) {
        tree[node] += lazy[node];
        propagate(l, r, node, lazy);
    }
    if(l > qr || r < ql) return;
    if(l >= ql && r <= qr) {
        tree[node] += val;
        lazy[node] += val;
        propagate(l, r, node, lazy);
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, 2 * node, ql, qr, val, tree, lazy);
    update(mid + 1, r, 2 * node + 1, ql, qr, val, tree, lazy);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
int query(int l, int r, int node, int ql, int qr, vector<int>& tree, vector<int>& lazy) {
    if(lazy[node] != 0) {
        tree[node] += lazy[node];
        propagate(l, r, node, lazy);
    }
    if(l > qr || r < ql) return INF;
    if(l >= ql && r <= qr) return tree[node];
    int mid = (l + r) / 2;
    int left = query(l, mid, 2 * node, ql, qr, tree, lazy);
    int right = query(mid + 1, r, 2 * node + 1, ql, qr, tree, lazy);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    return min(left, right);
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
        vector<int> tree(4 * n), lazy(4 * n);
        build(0, n - 1, 1, tree, v);
        int m;
        cin >> m;
        string s;
        getline(cin, s);
        while(m--) {
            getline(cin, s);
            stringstream ss(s);
            int num;
            vector<int> temp;
            while(ss >> num) {
                temp.push_back(num);
            }
            int l = temp[0], r = temp[1];
            if(temp.size() == 2) {
                if(l <= r) cout << query(0, n - 1, 1, l, r, tree, lazy) << endl;
                else cout << min(query(0, n - 1, 1, 0, r, tree, lazy), query(0, n - 1, 1, l, n - 1, tree, lazy)) << endl;
            } else {
                int val = temp[2];
                if(l <= r) update(0, n - 1, 1, l, r, val, tree, lazy);
                else {
                    update(0, n - 1, 1, 0, r, val, tree, lazy);
                    update(0, n - 1, 1, l, n - 1, val, tree, lazy);
                }
            }
        }
    }
}