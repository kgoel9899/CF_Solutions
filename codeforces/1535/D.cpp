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

int n, tot;
string s;
vector<int> tree;
int get(int node) {
    int tn = tot / 2, ind = 1;
    while(tn > node) {
        ind += tn;
        tn /= 2;
    }
    ind += node - tn;
    return ind;
}
void build(int st, int end, int node) {
    if(st == end) {
        tree[node] = 1;
        return;
    }
    int mid = (st + end) / 2;
    build(st, mid, 2 * node);
    build(mid + 1, end, 2 * node + 1);
    int pos = get(node);
    dbg(node, pos, s[pos]);
    if(s[pos] == '0') tree[node] = tree[2 * node];
    else if(s[pos] == '1') tree[node] = tree[2 * node + 1];
    else tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void update(int node) {
    if(node == 0) return;
    int pos = get(node);
    if(s[pos] == '0') tree[node] = tree[2 * node];
    else if(s[pos] == '1') tree[node] = tree[2 * node + 1];
    else tree[node] = tree[2 * node] + tree[2 * node + 1];
    update(node / 2);
}
// [0110][?1][1]
// [4567][23][1]
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        cin >> s;
        s = '#' + s;
        tot = s.size();
        dbg(s, tot);
        tree.clear();
        tree.resize(2 * tot + 5);
        build(0, tot - 1, 1);
        dbg(tree);
        int q;
        cin >> q;
        while(q--) {
            int ind;
            char val;
            cin >> ind >> val;
            s[ind] = val;
            int node = 0;
            int tn = 1;
            ind = tot - ind;
            while(ind > tn) {
                node += tn;
                ind -= tn;
                tn *= 2;
            }
            node += tn - ind + 1;
            dbg(ind, node);
            update(node);
            cout << tree[1] << endl;
        }
    }
}