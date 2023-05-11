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
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
int query(int l, int r, int node, int st, int end, vector<int>& tree) {
    if(l > end || r < st) return INF;
    if(st <= l && r <= end) return tree[node];
    int mid = (l + r) / 2;
    return min(query(l, mid, 2 * node, st, end, tree), query(mid + 1, r, 2 * node + 1, st, end, tree));
}
// editorial idea
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        set<int> s;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            s.insert(v[i]);
        }
        vector<int> tree(4 * n);
        build(0, n - 1, 1, v, tree);
        vector<int> ans(n);
        int ok = 1, nxt = 1;
        for(auto i : s) {
            if(i != nxt++) {
                ok = 0;
                break;
            }
        }
        if(ok && nxt == n + 1) ans[0] = 1;
        if(*s.begin() == 1) ans[n - 1] = 1;
        dbg(ans);
        if(ans[n - 1]) {
            int l = 0, r = n - 1;
            int curr = 1;
            for(int i=1;i<n;i++) {
                ans[n - i] = 1;
                if(v[l] == curr) l++;
                else if(v[r] == curr) r--;
                int mn = query(0, n - 1, 1, l, r, tree);
                curr++;
                if(mn != curr) break;
            }
        }
        for(auto i : ans) {
            cout << i;
        }
        cout << endl;
    }
} 