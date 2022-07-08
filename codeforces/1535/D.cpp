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

int k;
vector<int> tree;
string s, fin;
void build(int node, int low, int high) {
    if(low == high) {
        tree[node] = 1;
        return;
    }
    int mid = (low + high) / 2;
    build(2 * node, low, mid);
    build(2 * node + 1, mid + 1, high);
    dbg(node);
    if(fin[node] == '0') tree[node] = tree[2 * node];
    else if(fin[node] == '1') tree[node] = tree[2 * node + 1];
    else tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void update(int node) {
    if(node == 0) return;
    if(fin[node] == '0') tree[node] = tree[2 * node];
    else if(fin[node] == '1') tree[node] = tree[2 * node + 1];
    else tree[node] = tree[2 * node] + tree[2 * node + 1];
    update(node / 2);
}
int32_t main() {
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> k;
        cin >> s;
        s = '#' + s;
        fin = s;
        int len = (1 << k) / 2, last = 1, fill = s.size() - len;
        map<int, int> m;
        while(len != 0) {
            int temp = fill;
            for(int i=last;i<last+len;i++,temp++) {
                fin[temp] = s[i];
                m[i] = temp;
            }
            last += len;
            len /= 2;
            fill -= len;
        }
        dbg(fin);
        tree.clear();
        int sz = (1 << k);
        tree.resize(2 * sz);
        build(1, 0, sz - 1);
        dbg(tree);
        int q;
        cin >> q;
        dbg(m);
        while(q--) {
            int p;
            char c;
            cin >> p >> c;
            fin[m[p]] = c;
            update(m[p]);
            cout << tree[1] << endl;
        }
    }
}